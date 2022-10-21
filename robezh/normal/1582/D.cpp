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
const int N = (int)1e5 + 50;

int n;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
        }
        int st = n % 2 == 0 ? 0 : 3;
        if(st == 3) {
            int x = a[0], y = a[1], z = a[2];
            if(x + y != 0) {
                b[0] = z;
                b[1] = z;
                b[2] = -(x + y);
            } else if(x + z != 0) {
                b[0] = y;
                b[1] = -(x + z);
                b[2] = y;
            } else if(y + z != 0) {
                b[0] = -(y + z);
                b[1] = x;
                b[2] = x;
            }
        }
        for (int i = st; i < n; i += 2) {
            b[i] = -a[i + 1];
            b[i + 1] = a[i];
        }
        rep(i, 0, n) cout << b[i] << " ";
        cout << endl;
    }

}