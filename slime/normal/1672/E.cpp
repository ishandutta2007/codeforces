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
const int maxn = 500005;
int ask(int a) {
    cout << "? " << a << endl; fflush(stdout);
    int ans;
     cin >> ans;
     return ans;
}
int main() {
    int n;
    cin >> n;
    int l = 1, r = n * 2005;
    while (l < r) {
        int mid = (l + r) >> 1;
        int na = ask(mid);
        if (na == 1) r = mid;
        else l = mid + 1;
    }
    int nans = l;
    for (int i = 1; i <= n; i++) {
        int k = l / i;
        if (k == 0) continue;
        int res = ask(k);
        if (res == 0) continue;
        chkmin(nans, k * res);
    }
    cout << "! " << nans << endl;
    fflush(stdout);
    return (0-0); //<3
}