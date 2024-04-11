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

mt19937 rng(2333);


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pii> vs[3];
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            vs[(i + j) % 2 + 1].push_back({i, j});
        }
    }
    vector<vi> res(n + 1, vi(n + 1, 0));
    auto put_color = [&](int par, int col) {
        auto p = vs[par].back(); vs[par].pop_back();
        cout << col << " " << p.first << " " << p.second << endl;
        res[p.first][p.second] = col;
        fflush(stdout);

    };
    rep(it, 0, n * n) {
        int x;
//        x = rng() % 3 + 1;
        cin >> x;
        if(vs[2].empty()) {
            if(x != 1) put_color(1, 1);
            else put_color(1, 3);
        } else if(vs[1].empty()) {
            if(x != 2) put_color(2, 2);
            else put_color(2, 3);
        } else {
            if(x != 1) put_color(1, 1);
            else put_color(2, 2);
        }
    }

//    rep(i, 1, n + 1) {
//        rep(j, 1, n + 1) {
//            cout << res[i][j] << " ";
//        }
//        cout << endl;
//    }


}