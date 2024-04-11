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
const int N = 100;

int n, k;
int res[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        if(2 * k - 1 > n) {
            cout << -1 << endl;
        } else {
            int c = 0;
            rep(i, 0, n) {
                rep(j, 0, n) {
                    if(i == j && i %2 == 0 &&  c < k) {
                        c++;
                        cout << "R";
                    } else cout << ".";
                }
                cout << '\n';
            }
        }
    }

}