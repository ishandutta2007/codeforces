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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vi> res(n, vi());
    rep(i, 0, n) {
        if(i % 2 == 0) {
            rep(j, i * n, (i + 1) * n) res[j - i * n].push_back(j);
        } else {
            rep(j, i * n, (i + 1) * n) res[(i + 1) * n - 1 - j].push_back(j);
        }
    }
    rep(i, 0, n) {
        for (int x : res[i]) cout << x + 1 << " ";
        cout << endl;
    }

}