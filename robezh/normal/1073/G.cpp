#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <deque>
#include <stack>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 50, LOGN = 19, INF = (int)1e9;

int mm[N];
int n, m, q;


struct SA {
    int n;
    int rk[N], sa[N], ht[N];

    void build(string &str) {
        n = str.length() - 1;
        static int set[N], a[N];
        for(int i = 1; i <= n; i++) set[i] = str[i];
        sort(set + 1, set + n + 1);
        int *end = unique(set + 1, set + n + 1);
        for(int i = 1; i <= n; i++) a[i] = (int)(lower_bound(set + 1, end, str[i]) - set);

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

    void build(const int a[]) {
        n = sa.n + 1;
        for(int i = 0; i < n; i++){
            st[0][i] = a[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }
    int rmq(int l, int r){
        int k = mm[r - l + 1];
        return min(st[k][l], st[k][r-(1<<k)+1]);
    }

    int lcp(int l, int r) {
        assert(l != r);
        if(l < r) return rmq(l + 1, r);
        else return rmq(r + 1, l);
    }
}lcp_st;

string A, B;

struct MonS{
    ll sum;
    stack<P> S;

    void lim(int h) {
        int cnt = 0;
        while(!S.empty() && S.top().first > h) {
            sum -= 1LL * S.top().first * S.top().second;
            cnt += S.top().second;
            S.pop();
        }
        if(cnt > 0) {
            S.push({h, cnt});
            sum += 1LL * h * (cnt);
        }
    }

    void add(int x) {
        S.push({x, 1});
        sum += x;

    }

    void clear() {
        while(!S.empty()) S.pop();
        sum = 0;
    }

}Sa, Sb;

int len;
string str;
P p[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    mm[0]=-1;
    for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];


    cin >> len >> q;
    cin >> str;
    str = " " + str;
    sa.build(str);
    lcp_st.build(sa.ht);

    while(q--) {
        ll res = 0;
        cin >> n >> m;
        Sa.clear(), Sb.clear();
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            p[i].first = sa.rk[a], p[i].second = 0;
        }
        for(int i = n; i < n + m; i++) {
            int a; cin >> a;
            p[i].first = sa.rk[a], p[i].second = 1;
        }
        sort(p, p + n + m);
        for(int i = n + m - 1; i >= 0; i--) {
            if(i < n + m - 1) {
                int r = p[i+1].first;
                int l = p[i].first;
                if(l < r) {
                    int lcp = lcp_st.lcp(l, r);
                    Sa.lim(lcp);
                    Sb.lim(lcp);
                }
            }
            if(p[i].second) {
                res += Sa.sum;
                Sb.add(len - sa.sa[p[i].first] + 1);
            }
            else {
                res += Sb.sum;
                Sa.add(len - sa.sa[p[i].first] + 1);
            }
        }
        cout << res << "\n";

    }

}