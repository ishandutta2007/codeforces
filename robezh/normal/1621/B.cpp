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
const int N = (int)1e5 + 5;
const int INF = (int)2e9 + 5;

int n, l[N], r[N], c[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 1, n + 1) {
            cin >> l[i] >> r[i] >> c[i];
        }
//        fill(res, res + n + 1, INF);
        int mx = -INF, mn = INF, bestmx = INF, bestmn = INF, best2 = INF;
        rep(i, 1, n + 1) {
            if(l[i] == mn && r[i] == mx) {
                best2 = min(best2, c[i]);
            } else if(l[i] <= mn && r[i] >= mx) {
                best2 = c[i];
            } else if(l[i] < mn || r[i] > mx) {
                best2 = INF;
            }

            if(l[i] < mn) {
                mn = l[i];
                bestmn = c[i];
            } else if(l[i] == mn) {
                bestmn = min(bestmn, c[i]);
            }
            if(r[i] > mx) {
                mx = r[i];
                bestmx = c[i];
            } else if(r[i] == mx) {
                bestmx = min(bestmx, c[i]);
            }
            cout << min(best2, bestmx + bestmn) << '\n';
        }
    }

}