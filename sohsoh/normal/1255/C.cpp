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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

map<pll, vector<ll>> mp;
ll n;
ll cnt[MAXN] = {0}, ans[MAXN];

void mp_add(pll p, ll x) {
    if (mp.find(p) == mp.end()) mp.insert({p, {}});
    mp[p].push_back(x);
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n - 2; i++) {
        ll a[3];
        for (int j = 0; j < 3; j++) cin >> a[j];
        sort(a, a + 3);
        mp_add({a[0], a[1]}, a[2]);
        mp_add({a[0], a[2]}, a[1]);
        mp_add({a[1], a[2]}, a[0]);

        cnt[a[0]]++;
        cnt[a[1]]++;
        cnt[a[2]]++;
    }

    ll start = -1;
    ll sec = -1;
    for (int i = 0; i < MAXN; i++) if (cnt[i] == 1) start = i;
    for (ll i = 0; i < MAXN; i++) if (cnt[i] == 2 && mp.find({min(start, i), max(start, i)}) != mp.end()) sec = i;
    ans[0] = start;
    ans[1] = sec;
    set<ll> st;
    st.insert(ans[0]);
    st.insert(ans[1]);
    for (int i = 2; i < n; i++) {
        ll p = ans[i - 1], p2 = ans[i - 2];
        vector<ll> poss = mp.find({min(p, p2), max(p, p2)}) -> Y;
        for (ll x : poss) {
            if (st.find(x) == st.end()) {
                ans[i] = x;
                st.insert(x);
            }
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << sep; cout << endl;
    return 0;
}