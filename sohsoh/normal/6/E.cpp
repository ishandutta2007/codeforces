/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
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

ll A[MAXN], n, k;

int main() {
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> A[i];
    multiset<ll> st;

    ll pl = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        ll mn = INF, mx = -1 * INF;
        if (!st.empty()) mx = *st.rbegin(), mn = *st.begin();
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
        if (mx - mn > k) break;
        st.insert(A[i]);
        pl = i;
    }

    ll ans = n - pl;
    for (int i = n - 2; i >= 0; i--) {
        st.erase(st.find(A[i + 1]));

        while (pl > 0) {
            pl--;
            ll mn = INF, mx = -1 * INF;
            if (!st.empty()) mx = *st.rbegin(), mn = *st.begin();
            mn = min(mn, A[pl]);
            mx = max(mx, A[pl]);
            if (mx - mn > k) {
                pl++;
                break;
            }

            st.insert(A[pl]);
        }

        ans = max(ans, i - pl + 1);
    }


    vector<pll> v;
    multiset<ll> st2;
    for (int i = 0; i < ans; i++) st2.insert(A[i]);
    if (*(st2.rbegin()) - *(st2.begin()) <= k) v.push_back({1, ans});
    for (int i = ans; i < n; i++) {
        auto it = st2.find(A[i - ans]);
        st2.insert(A[i]);
        st2.erase(it);
        if ((*(st2.rbegin())) - (*(st2.begin())) <= k) v.push_back({i - ans + 2, i + 1});
    }

    cout << ans << sep << v.size() << endl;
    for (pll e : v) cout << e.X << sep << e.Y << endl;


    return 0;
}