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
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
int a[maxn];
int n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        vi a;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x = abs(x);
            a.pb(x);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < a.size(); ) {
            int j = i;
            while (j < a.size() && a[j] == a[i]) j += 1;
            int cr = 2;
            if (a[i] == 0) cr = 1;
            ans += min(j - i, cr);
            i = j;
        }
        cout << ans << endl;
    }
    return (0-0); //<3
}