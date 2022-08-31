//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int b[maxn], a[maxn];
vi cc[maxn];
int n;
int fl[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) fl[i] = 0, cc[i].clear();
        for (int i = 1; i <= n; i++) 
            cc[a[i]].pb(i), b[i] = -1;
        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (cc[i].size()) {
                k++;
                int pl = -1, nres = maxn;
                for (auto v : cc[i])
                    if (chkmin(nres, (int)cc[v].size())) pl = v;
                b[pl] = i;
                fl[i] = 1;
            }
        }
        vi nu, npl;
        for (int i = 1; i <= n; i++) {
            if (b[i] == -1) npl.pb(i);
            if (cc[i].size() == 0) nu.pb(i);
        }
        for (int i = 0; i < nu.size(); i++)
            b[npl[i]] = nu[i];
        for (int i = 0; i < nu.size(); i++) {
            int cr = npl[i];
            if (b[cr] == cr) {
                int nx = npl[(i + 1) % npl.size()];
                swap(b[cr], b[nx]);
            }
        }
        printf("%d\n", k);
        for (int i = 1; i <= n; i++)
            printf("%d ", b[i]);
        printf("\n");
    }
    return 0;
}