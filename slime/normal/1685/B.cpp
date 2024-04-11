//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
char s[maxn];
int ed[27];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x[2];
        int u, v;
        scanf("%d%d%d%d", &u, &v, &x[0], &x[1]);
        int cnt[2] = {u + x[0] + x[1], v + x[0] + x[1]};
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            cnt[s[i] - 'A'] -= 1;
        }
        int flag = 1; 
        int sum = 0;
        vector<pi> h;
        if (cnt[0] != 0 || cnt[1] != 0) flag = 0;
        else {
            s[n + 1] = 'C';
            for (int i = 1; i <= n; ) {
                int j = i;
                while (j < n && s[j] != s[j + 1]) j += 1;
                int clen = j - i + 1;
                if (clen % 2) sum += clen / 2;
                else
                    h.pb(mp(clen, s[i] - 'A'));
                i = j + 1;
            }
            sort(h.begin(), h.end());
           // cout << sum << endl;
            for (auto w : h) {
                pi v = mp(w.se, w.fi);
                //cout << v.fi << ' ' << v.se << endl;
                int tr = v.se / 2;
                if (x[v.fi] >= tr) x[v.fi] -= tr;
                else {
                    int cur = min(x[v.fi], tr);
                    x[v.fi] -= cur;
                    tr -= cur; tr -= 1;
                    x[v.fi ^ 1] -= min(x[v.fi ^ 1], tr);
                }
            }
            if (x[0] + x[1] > sum) flag = 0;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return (0-0); //<3
}