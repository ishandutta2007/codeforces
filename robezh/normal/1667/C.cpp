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

// n = 5
// X....
// ..X..
// .X...
// .....
// .....

// n = 8
// X.......
// ..X.....
// ....X...
// .X......
// ...X....
// ........
// ........
// ........


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pii> res;
    if(n == 1) {
        cout << "1\n1\n1\n" << endl;
        return 0;
    }
    while(n % 3 != 2) {
        res.push_back({n, n});
        n--;
    }
    int k = (2 * n - 1) / 3;
    res.push_back({1, 1});
    rep(i, 0, k / 2) {
        res.push_back({2 + i, 3 + 2 * i});
        res.push_back({k / 2 + 2 + i, 2 + 2 * i});
    }
    cout << sz(res) << '\n';
    for (auto p : res) cout << p.first << " " << p.second << '\n';


}