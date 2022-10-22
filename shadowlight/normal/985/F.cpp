#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll P1 = 1e9 + 7;
const ll P2 = 1e5 + 7;
const ll P3 = 1e7 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = 31;

/// DA DA DA PO 3 MODULYAM
/// I CHTO?

struct Hashs {
    vector <vector <ll> > hashs;
    vector <ll> pows;
    ll P;
    Hashs(string &s, ll P) : P(P) {
        ll n = s.size();
        pows.resize(n, 0);
        hashs.resize(n, vector <ll> (Q, 0));
        hashs[0][s[0] - 'a']= 1;
        pows[0] = 1;
        for (ll i = 1; i < n; i++) {
            for (ll j = 0; j < Q; j++) {
                hashs[i][j] = hashs[i - 1][j] * 2 % P;
            }
            ll c = s[i] - 'a';
            hashs[i][c] = (hashs[i][c] + 1) % P;
            pows[i] = pows[i - 1] * 2 % P;
        }
    }
    vector <ll> get_hash(ll l, ll r) {
        if (!l) {
            return hashs[r];
        }
        vector <ll> res(Q, 0);
        for (ll i = 0; i < Q; i++) {
            res[i] = (hashs[r][i] - hashs[l - 1][i] * pows[r - l + 1] % P + P) % P;
        }
        return res;
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector <Hashs> data;
    data.push_back(Hashs(s, P1));
    data.push_back(Hashs(s, P2));
    data.push_back(Hashs(s, P3));
    for (ll i = 0; i < m; i++) {
        ll x, y, len;
        cin >> x >> y >> len;
        x--, y--;
        bool can = true;
        for (ll j = 0; j < 3; j++) {
            auto a = data[j].get_hash(x, x + len - 1);
            auto b = data[j].get_hash(y, y + len - 1);
            set <ll> all;
            for (ll x : b) {
                all.insert(x);
            }
            for (ll d = 0; d < Q; d++) {
                if (!a[d]) continue;
                if (all.find(a[d]) == all.end()) {
                    can = false;
                    break;
                }
            }
            if (!can) break;
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
}