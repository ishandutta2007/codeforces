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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<vector<string>> v;

int main() {
    fast_io;
    ll n, m;
    cin >> n >> m;
    vector<string> t;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.push_back(s);
    }

    v.push_back(t);
    ll ans = 0;
    while (m--) {
        bool ok = true;
        for (vector<string> e : v) {
            char lc = 'a';
            for (string s : e ) {
                if (s.front() >= lc) lc = s.front();
                else ok = false;
            }
        }

        ll ts = v.size();
        for (int i = 0; i < ts; i++) {
            vector<string> tmp;
            char lc = 'a';
            for (int j = 0; j < v[i].size(); j++) {
//                debug(v[i][j])
                if (v[i][j].front() == lc) {
                    v[i][j].erase(v[i][j].begin());
                    tmp.push_back(v[i][j]);
                } else {
                    lc = v[i][j].front();
                    v[i][j].erase(v[i][j].begin());
                    if (ok && !tmp.empty()) {
                        v.push_back(tmp);
                        tmp.clear();
                    }

                    tmp.push_back(v[i][j]);
                }
            }

            if (ok && !tmp.empty()) v.push_back(tmp);
        }

        if (ok) for (int i = 0; i < ts; i++) v.erase(v.begin());
        if (!ok) ans++;
    }

    cout << ans << endl;
    return 0;
}