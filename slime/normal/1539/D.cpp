#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<ll, ll>
#define maxn 100005
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
ll a[maxn], b[maxn];
int main() {
    int n;
    cin >> n;

    multiset<pi> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        s.insert(mp(b[i], a[i]));
    }
    ll ans = 0;
    ll cr = 0;
    while (s.size()) {
        pi cur = *s.begin();
        s.erase(s.find(cur));
        ll mr = 0;
        if (cur.fi <= cr) {
            ans += cur.se;
            cr += cur.se;
            continue;
        }
        else {
            mr = cur.fi - cr;
            s.insert(cur);
            pi cur = *(--s.end());
            s.erase(s.find(cur));
            ll tb = min(mr, cur.se);
            cur.se -= tb;
            if (cur.se) s.insert(cur);
            ans += 2 * tb;
            cr += tb;
        }
    }
    cout << ans << endl;
    return 0;
}