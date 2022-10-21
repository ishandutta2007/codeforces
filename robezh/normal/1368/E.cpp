#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
const int N = (int)4e5 + 50;

int n, m;
int dis[N];
struct edge {
    int u, v;
} e[N];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, m) cin >> e[i].u >> e[i].v;
        sort(e, e + m, [](const edge &e1, const edge &e2) {
            return e1.u < e2.u;
        });
        fill(dis, dis + n + 1, 0);
        vi del;
        rep(i, 0, m) {
            if(dis[e[i].u] < 2) dis[e[i].v] = max(dis[e[i].u] + 1, dis[e[i].v]);
        }
        rep(i, 1, n + 1) if(dis[i] == 2) del.push_back(i);
        cout << sz(del) << '\n';
        for(int x : del) cout << x << " ";
        cout << '\n';

    }


}