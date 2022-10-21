#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, LOGN = 17, INF = (int)1e9;

int mm[N];
int n, k;

struct SA {
    int n;
    int rk[N], sa[N], ht[N];

    void build(int num[], int len) {
        n = len;
        static int set[N], a[N];
        for(int i = 1; i <= n; i++) set[i] = num[i];
        sort(set + 1, set + n + 1);
        int *end = unique(set + 1, set + n + 1);
        for(int i = 1; i <= n; i++) a[i] = (int)(lower_bound(set + 1, end, num[i]) - set);

        static int fir[N], sec[N], tmp[N], buc[N];
        fill(buc, buc + n + 1, 0);
        for(int i = 1; i <= n; i++) buc[a[i]]++;
        for(int i = 1; i <= n; i++) buc[i] += buc[i-1];
        for(int i = 1; i <= n; i++) rk[i] = buc[a[i]-1] + 1;

        for(int t = 1; t <= n; t *= 2) {
            for(int i = 1; i <= n; i++) fir[i] = rk[i];
            for(int i = 1; i <= n; i++) sec[i] = i + t > n ? 0 : rk[i + t];

            fill(buc, buc + n + 1, 0);
            for(int i = 1; i <= n; i++) buc[sec[i]]++;
            for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
            for(int i = 1; i <= n; i++) tmp[n - (--buc[sec[i]])] = i;

            fill(buc, buc + n + 1, 0);
            for(int i = 1; i <= n; i++) buc[fir[i]]++;
            for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
            for(int j = 1, i; j <= n; j++) i = tmp[j], sa[buc[fir[i]]--] = i;

            bool unique = true;
            for (int j = 1, i, last = 0; j <= n; j++)
            {
                i = sa[j];
                if (!last) rk[i] = 1;
                else if (fir[i] == fir[last] && sec[i] == sec[last]) rk[i] = rk[last], unique = false;
                else rk[i] = rk[last] + 1;

                last = i;
            }

            if (unique) break;
        }



        for(int i = 1, k = 0; i <= n; i++) {
            if(rk[i] == 1) k = 0;
            else {
                if(k > 0) k--;
                int j = sa[rk[i]-1];
                while(i + k <= n && j + k <= n && a[i + k] == a[j + k]) k++;
            }
            ht[rk[i]] = k;
        }
    }
} sa;

struct ST {
    int n;
    int st[LOGN + 1][N];

    void build() {
        n = sa.n + 1;
        for(int i = 0; i < n; i++){
            st[0][i] = sa.ht[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }
    int rmq(int l, int r){
        int k = mm[r - l + 1];
//        assert(k == 0);
        return min(st[k][l], st[k][r-(1<<k)+1]);
    }

    int lcp(int l, int r) {
        if(l < r) return rmq(l + 1, r);
        else return rmq(r + 1, l);
    }
}st;

int num[N];
map<int, vector<int> > aper;

int find(int i) {
    int x = num[i];
    for(int loc : aper[x]) {
        if(loc > i && st.lcp(sa.rk[i], sa.rk[loc]) >= loc - i) return loc - i;
    }
    return -1;
}

int main() {
    mm[0]=-1;
    for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        aper[num[i]].push_back(i);
    }
    sa.build(num, n);
    st.build();
    vector<int> res;
    for(int i = 1; i <= n; ) {
        int len = find(i);
        if(len == -1) res.push_back(num[i++]);
        else i += len, res.clear();
    }
    cout << res.size() << "\n";
    for(int x : res) cout << x << " ";
    cout << "\n";


}