#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, INF = (int)1e9, mod = (int)1e9 + 7;

int n, cat[N], mn_len = INF;
string s[3];
ll add[N];

struct node {
    int f, las;
    int sz[3];

    ll t_sz() {
        return 1LL * sz[0] * sz[1] * sz[2] % mod;
    }
} u[N];


string str;

struct SA {
    int n;
    // ht[i] = lcp(suffix[sa[i]], suffix[sa[i-1]])
    int rk[N], sa[N], ht[N];

    void build(string str) {
        n = str.length() - 1;
//        str = " " + str;
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

void add_seg(int l, int r, ll val) {
    if(val == 0) return ;
    add[l] += val;
    add[r+1] -= val;
}

vector<int> in[N];


int find(int i) {return u[i].f == i ? i : u[i].f = find(u[i].f);}
void unite(int i, int j, int cur) {
    i = find(i), j = find(j);
    if(i == j) return ;
    add_seg(cur + 1, u[i].las, u[i].t_sz());
    add_seg(cur + 1, u[j].las, u[j].t_sz());
    u[i].f = j;
    for(int k = 0; k < 3; k++) u[j].sz[k] += u[i].sz[k];
    u[j].las = cur;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    n = 3;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        mn_len = min(mn_len, (int)s[i].length());
        str.push_back('#');
        int len = str.length();
        u[len-1].f = len - 1;
        u[len-1].las = INF;
        str += s[i];
        int newlen = str.length();
        for(int j = len; j < newlen; j++) {
            u[j].f = j;
            u[j].sz[i] = 1;
            u[j].las = INF;
        }
    }
    sa.build(str);
    for(int j = 2; j <= sa.n; j++) {
        in[sa.ht[j]].push_back(j);
    }
    for(int j = sa.n; j >= 0; j--) {
        for(int cur : in[j]) {
            unite(sa.sa[cur], sa.sa[cur-1], j);
        }
    }
    for(int i = 1; i <= mn_len; i++) {
        add[i] += add[i-1];
        cout << add[i] % mod << " ";
    }
    cout << endl;



}