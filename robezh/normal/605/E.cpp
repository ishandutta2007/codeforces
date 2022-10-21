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
const int N = 1005;
const double INF = 1e18;

int n;
int p[N][N];
double dis[N];
double csum[N];
double bad[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) cin >> p[i][j];
    }
    fill(dis, dis + n, INF);
    dis[n - 1] = 0;
    fill(bad, bad + n, 1);
    rep(it, 0, n) {
        int i = -1;
        rep(j, 0, n) {
            if(!vis[j] && (i == -1 || dis[j] < dis[i])) i = j;
        }
        if(i == 0) {
            cout << fixed << setprecision(10) << dis[i] << endl;
            return 0;
        }
        vis[i] = true;
        rep(j, 0, n) {
            if(!p[j][i] || i == j) continue;
            double pj = 1.0 * p[j][i] / 100;

            csum[j] += 1.0 * (bad[j] * pj) * (dis[i] + 1);
            bad[j] *= (1 - pj);

//            cout << i << " " << dis[i] << ", " << j << " " << (csum[j] + (bad[j])) / (1 - bad[j]) << endl;
            dis[j] = min(dis[j], (csum[j] + (bad[j])) / (1 - bad[j]));
        }
    }

}