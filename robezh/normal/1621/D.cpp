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
const int N = 505;

int n;
int a[N][N];
const int INF = (int)1e9 + 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        ll sum = 0;
        rep(i, 0, 2 * n) {
            rep(j, 0, 2 * n) {
                cin >> a[i][j];
                if (i >= n && j >= n) sum += a[i][j];
            }
        }


        vector<pii> vs = {{0, n}, {0, 2 * n - 1}, {n - 1, n}, {n - 1, 2 * n - 1},
                          {n, 0}, {2 * n - 1, 0}, {n, n - 1}, {2 * n - 1, n - 1}};

        int add = INF;
        for(auto p : vs) {
            add= min (add, a[p.first][p.second]);
        }
        cout << sum  + add << '\n';
    }

}