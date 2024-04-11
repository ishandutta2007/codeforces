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
set<int> r[maxn];
int ans = 0;
bool chk(int a) {
    if (r[a].empty()) return 1;
    if (*r[a].rbegin() <= a) return 1;
    return 0;
}
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, s;
        cin >> n >> s;
        int r = ((n + 1) / 2);
        if (n % 2 == 0) r += 1;
        printf("%d\n", s / r);
    }
    return (0-0); //<3
}