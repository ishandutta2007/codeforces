#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 200005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n, s;
ll a[maxn];
int st[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;
        //cout << "AF" << endl;
        int l = x, r = x;
        while (m--) {
            int a, b;
            cin >> a >> b;
            if (max(a, l) <= min(r, b))
                r = max(r, b), l = min(a, l);
        }
        cout << r - l + 1 << endl;
    }
    return 0;
}