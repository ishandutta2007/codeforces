#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e6 + 50, M = 8200;

int n, a[N];
vector<int> xs[M];
vector<pii> ear;
bool vis[M];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i], xs[a[i]].push_back(i);
    ear.push_back({0, -1});
    rep(v, 0, M) {
        fill(vis, vis + M, 0);
        vector<pii> gear;
        int c = 0;
        for (int i : xs[v]) {
            int r = c;
            while(r < sz(ear) && ear[r].second < i) {
                if(!vis[ear[r].first])  {
                    gear.push_back({ear[r]});
                    vis[ear[r].first] = true;
                }
                r++;
            }
            for (int j = c; j < r; j++) {
                int nxt = ear[j].first ^ v;
                if(!vis[nxt]) {
                    gear.push_back({nxt, i});
                    vis[nxt] = true;
                }
            }
            c = r;
        }
        while(c < sz(ear)) {
            if(!vis[ear[c].first])  {
                gear.push_back({ear[c]});
                vis[ear[c].first] = true;
            }
            c++;
        }
        ear = gear;
    }

    sort(all(ear));
    cout << sz(ear) << '\n';
    rep(i, 0, sz(ear)) cout << ear[i].first << " ";
    cout << endl;

}