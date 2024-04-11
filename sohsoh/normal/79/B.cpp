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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, k, t;
ll ps[MAXN] = {0};
set<pll> st;

int main() {
    fast_io;
    cin >> n >> m >> k >> t;
    fill(ps, ps + MAXN, m);
    ps[0] = 0;
    while (k--) {
        ll x, y;
        cin >> x >> y;
        ps[x]--;
        st.insert({x, y});
    }

//    debug(ps[1])

    for (int i = 1; i < MAXN; i++) ps[i] += ps[i - 1];
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (st.find({x, y}) != st.end()) {
            cout << "Waste" << endl;
            continue;
        }

        ll c = 0;
        c += ps[x - 1];
        for (int i = 0; i < y; i++) {
            if (st.find({x, i + 1}) != st.end()) continue;
            c++;
        }
        c--;

        if (c % 3 == 0) cout << "Carrots" << endl;
        else if (c % 3 == 1) cout << "Kiwis" << endl;
        else cout << "Grapes" << endl;
    }
    return 0;
}