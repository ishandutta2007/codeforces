#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int a, b;
int psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 1, N) psum[i] = psum[i - 1] ^ i;
    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        int rem = (b ^ psum[a - 1]);
        if(rem == 0) cout << a << '\n';
        else if(rem == a) cout << a + 2 << "\n";
        else cout << a + 1 << "\n";
    }

}