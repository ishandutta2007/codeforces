/*
	:_:
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 99824353; // 1e9 + 9;

pll A[MAXN];
ll n;
set<pll> st;

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].X;
        A[i].Y = i;
        st.insert({i, A[i].X});
    }

    sort(A, A + n);
    ll ans = 0, val = 0;
    ll rem = n;
    for (int i = 0; i < n - 2; i++) {
        auto it = st.find({A[i].Y, A[i].X});
        auto ite = st.end();
        ite--;
        if (it == st.begin() || it == ite) {
            ans += (A[i].X - val) * (rem - 2);
            val += (A[i].X - val);
            st.erase(it);
            rem--;
        } else {
            auto nxt = it, prv = it;
            nxt++; prv--;
            ans += min(nxt -> Y, prv -> Y) - val;
            st.erase(it);
            rem--;
        }

    }

    cout << ans << endl;
    return 0;
}