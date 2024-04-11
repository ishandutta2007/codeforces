#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        bool good = false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                good = true;
                cout << n / i << " " << n / i * (i - 1) << '\n';
                break;
            }
        }
        if(!good) cout << 1 << " " << n - 1 << '\n';
    }

}