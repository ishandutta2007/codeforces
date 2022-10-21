#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int N = (int)1e5 + 50;

int n;
pll p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll csum = 0, tcost = 0;
    rep(i, 0, n) cin >> p[i].first >> p[i].second, csum += p[i].first;
    tcost = csum * 2;


    ll cpt = csum;
    sort(p, p + n, [](const pll &p1, const pll &p2) {
        return p1.second < p2.second;
    });
    for(int i = n - 1; i >= 0; i--) {
        ll mxtake = max(0LL, min(cpt - p[i].second, p[i].first));
        tcost -= mxtake;
        cpt -= mxtake;
    }
    cout << tcost << endl;


}