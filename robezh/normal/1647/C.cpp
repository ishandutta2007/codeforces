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

const int N = 105;

int n, m;
string str[N];

struct P{
    int r0, c0, r1, c1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> str[i];

        if(str[0][0] == '1') {
            cout << -1 << '\n';
            continue;
        }
        vector<P> res;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if(str[i][j] == '1') {
                    if(i) res.push_back({i - 1, j, i, j});
                    else res.push_back({i, j - 1, i, j});
                }
            }
        }
        cout << sz(res) << '\n';
        for(auto &p : res) cout << p.r0 + 1 << " " << p.c0 + 1 << " " << p.r1 + 1 << " " << p.c1 + 1 << '\n';
    }
}