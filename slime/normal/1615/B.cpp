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
int n;
int cal(int a, int b) {
    int c = (1 << (b + 1));
    ll cur = (1 << b) * (a / c); a %= c;
    if (a >= c / 2) cur += (a - c / 2 + 1);
    return cur;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int mx = 0;
        for (int j = 0; j < 20; j++)
            chkmax(mx, cal(r, j) - cal(l - 1, j));
        printf("%d\n", r - l + 1 - mx);
    }
    return (0-0); //<3
}