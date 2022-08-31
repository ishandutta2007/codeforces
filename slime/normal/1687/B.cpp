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
int fl[maxn];
int n, m;
int q() {
    cout << "? ";
    for (int i = 1; i <= m; i++)
        cout << fl[i];
    cout << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    cin >> n >> m;
    vector<pi> cur;
    for (int i = 1; i <= m; i++) {
        fl[i] = 1;
        cur.pb(mp(q(), i));
        fl[i] = 0;
    }
    sort(cur.begin(), cur.end());
    int lans = 0;
    for (auto v : cur) {
        fl[v.se] = 1;
        int nans = q();
        if (nans == lans + v.fi) lans = nans;
        else 
            fl[v.se] = 0;
    }
    cout << "! " << lans << endl;
    fflush(stdout);
    return (0-0); //<3
}