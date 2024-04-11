#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 55;

int n, a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        int s = 0;
        rep(i, 0, n)  cin >> a[i], s += a[i];
        if(s == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            sort(a, a + n);
            if(s > 0) reverse(a, a + n);
            rep(i, 0, n) cout << a[i] << " ";
            cout << '\n';
        }

    }

}