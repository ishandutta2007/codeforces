#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, x, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> x >> m;
        int l = x, r = x;
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            if(a <= r && b >= l) {
                l = min(a, l);
                r = max(r, b);
            }
        }
        cout << r - l + 1 << '\n';
    }

}