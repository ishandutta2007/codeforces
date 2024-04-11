//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int cnt[maxn];
int hv[maxn];
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++) cnt[i] = 0;

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), cnt[a[i]] += 1;
        int cr = 0;
        vi res;
        for (int i = 1; i <= n; ) {
            int j = i;
            cr = 0;
            while (j <= n) {
                cnt[a[j]] -= 1;
                hv[a[j]] = 1;
                while (hv[cr]) cr += 1;
                if (!cnt[cr]) break;
                j += 1;
            }
            res.pb(cr);
            for (int m = i; m <= j; m++) hv[a[m]] = 0;
            i = j + 1;
        }
        cout << res.size() << endl;
        for (auto v : res) printf("%d ", v);
        printf("\n");
    }
    return (0-0); //<3
}