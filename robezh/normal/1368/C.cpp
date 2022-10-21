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

const int N = 1005;

vector<pii> res;
int mp[N][N];

void add(int u, int v) {
    res.push_back({u, v});
    mp[u + 5][v + 2] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < 2 * n + 1; i++) {
        add(0, i);
        if(i % 2 == 1) add(1, i), add(-1, i);
    }
    if(n % 2 == 0) {
        for(int i = 1; i < 2 * n + 1; i += 4) {
            add(2, i);
            add(2, i + 1);
            add(2, i + 2);
            add(-2, i);
            add(-2, i + 1);
            add(-2, i + 2);
        }
        for(int i = 0; i <= 3; i++) add(i, -1), add(i, 2 * n + 1);
        for(int i = -1; i <= 2 * n + 1; i++) add(4, i);
    } else {
        add(-1, -1);
        add(0, -1);
        add(1, 2 * n + 1);
        add(0, 2 * n + 1);
        for(int i = 1; i <= 2 * n + 1; i += 4) {
            add(2, i);
            add(2, i + 1);
            add(2, i + 2);
        }
        for(int i = -1; i < 2 * n + 1; i += 4) {
            add(-2, i);
            add(-2, i + 1);

            add(-2, i + 2);
        }
    }
    cout << res.size() << '\n';
    for(auto p : res) cout << p.first << " " << p.second << '\n';

//    for(int k = 0; k < 20; k++) {
//        for(int i =0; i < 2 * n + 10; i++) {
//            cout << mp[k][i];
//        }
//        cout << endl;
//
//    }
}