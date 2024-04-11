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
const int maxn =200005;
int a[maxn];

multiset<ll> x;
bool chk(ll u) {
    if (x.find(u) != x.end()) {
        x.erase(x.find(u));
        return 1;
    }
    if (u == 1) return 0;
    if (chk(u / 2))
        return chk((u + 1) / 2);
    else return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        x.clear();
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) x.insert(a[i]);
        ll s = 0;
        for (int i = 1; i <= n; i++) s += a[i];
        if (chk(s)) printf("YES\n");
        else printf("NO\n");
    }
    return (0-0); //<3
}