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
typedef pair<int, int> P;
const int N = (int)1e6 + 50;

int n, k;
int p[N], a[N];
vector<pii> las[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(p, p + N, 1);
    rep(i, 2, N) {
        if(p[i]) for (int j = 2 * i; j < N; j += i) p[j] = 0;
    }

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) las[i].clear();
        ll res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int c = i % k;
            if(a[i] > 1) las[c].push_back({a[i], i});

            if(!las[c].empty() && p[las[c].back().first]) {

                if(sz(las[c]) >= 2) {
                    res += (las[c][sz(las[c]) - 2].second - 1 - las[c].back().second) / k + 1;
                } else {
                    res += (n - 1 - las[c].back().second) / k + 1;
                }
            }
            if(a[i] > 1 && p[a[i]]) res--;
        }
        cout << res << '\n';

    }

}