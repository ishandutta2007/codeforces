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

int n, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> a >> b;
        if(a + b > n - 2 || abs(a - b) > 1) {
            cout << -1 << "\n";
            continue;
        }

        if(a != b) {
            vi res;
            bool swapped = a > b;
            if(swapped) swap(a, b);
            rep(i, 0, a + 1) {
                res.push_back(2 * i + 2);
                res.push_back(2 * i + 1);
            }
            rep(i, 2 * a + 3, n + 1) res.push_back(i);

            if(swapped) {
                for(int &x : res) x = n + 1 - x;
            }
            for (int x : res) cout << x << " ";
            cout << '\n';
        } else if(a == b) {
            int r = n, l = 1;
            while(a) {
                cout << r << " " << l << " ";
                a--;
                r--, l++;
            }
            for (int i = r; i >= l; i--) cout << i << " ";
            cout << '\n';
        }
    }

}