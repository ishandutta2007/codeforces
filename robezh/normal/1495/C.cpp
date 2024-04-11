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

int n, m;
string str[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> str[i];
        int st = (m % 3 == 0 ? 1 : 0);
        for (int j = st; j < m; j += 3) {
            rep(i, 0, n) str[i][j] = 'X';
        }
        for (int j = st; j < m; j += 3) {
            if(j + 3 >= m) continue;
            if(1 < n && (str[1][j + 1] == 'X' || str[1][j + 2] == 'X')) {
                str[1][j + 1] = str[1][j + 2] = 'X';
            } else {
                str[0][j + 1] = str[0][j + 2] = 'X';
            }
        }
        rep(i, 0, n) cout << str[i] << '\n';
    }
}