#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 305;
int n, m;
int a[N][N];

int get(int i, int j) {
    return (i >= 1) + (i + 1 < n) + (j >= 1) + (j + 1 < m);
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(a[i][j] > get(i, j)) {
                cout << "NO\n";
                return ;
            }
            else a[i][j] = get(i, j);
        }
    }
    cout << "YES\n";
    rep(i, 0, n) {
        rep(j, 0, m) cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}