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

int n, m;
int in[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        fill(in, in + n, 0);
        rep(i, 0, m) {
            int a, b, c; cin >> a >> b >> c;
            a--, b--, c--;
            in[b] = 1;
        }
        int rt = -1;
        rep(i, 0, n) if(!in[i]) rt = i;
        rep(i, 0, n) {
            if(i != rt) cout << rt + 1 << " " << i + 1 << '\n';
        }
    }
}