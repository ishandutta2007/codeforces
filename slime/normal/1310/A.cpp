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
int a[maxn], t[maxn];
int main() {
    int n;
    cin >> n;
    vector<pi> cur;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i], cur.pb(mp(a[i], t[i]));
    sort(cur.begin(), cur.end());
    priority_queue<int> s;
    ll sum = 0;
    int cr = 0;
    ll ans = 0;
    for (auto v : cur) {
        while (s.size() && cr < v.fi) {
            sum -= s.top();
            ans += sum;
            s.pop();
            cr += 1;
        }
        cr = v.fi;
        //cout << v.fi << ' ' << v.se << ' ' << sum << ' ' << ans << endl;
        sum += v.se;
        s.push(v.se);
    }
    while (s.size())
    {
        sum -= s.top();
        ans += sum;
        s.pop();
        cr += 1;
    }
    cout << ans << endl;
    return 0;
}