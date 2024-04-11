#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

int n;
string sa, sb;
int bit[N];

void add(int x, int val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

vector<int> vs[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> sa >> sb;
        rep(i, 0, 26) vs[i].clear();
        rep(i, 0, n) {
            vs[sa[i] - 'a'].push_back(i);
        }
        rep(i, 0, 26) reverse(all(vs[i]));
        fill(bit, bit + n, 0);
        rep(i, 0, n) add(i, 1);
        ll res = INF;
        ll base = 0;
        for (int i = 0; i < n; i++) {
            int fircur = N;
            rep(j, 0, sb[i] - 'a') {
                if(!vs[j].empty()) fircur = min(fircur, vs[j].back());
            }
            if(fircur != N) res = min(res, base + get(fircur - 1));
            if(vs[sb[i] - 'a'].empty()) break;
            int loc = vs[sb[i] - 'a'].back(); vs[sb[i] - 'a'].pop_back();
            base += get(loc - 1);
            add(loc, -1);
        }
        if(res == INF) res = -1;
        cout << res << '\n';
    }


}