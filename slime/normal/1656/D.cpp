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
const int maxn = 200005;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll cur = 1;
        while (n % 2 == 0) {
            cur *= 2;
            n /= 2;
        }
        if (n == 1) printf("-1\n");
        else {
            if (cur >= (n + 1) / 2) printf("%lld\n", n);
            else printf("%lld\n", cur * 2);
        }
    }
    return (0-0); //<3
}