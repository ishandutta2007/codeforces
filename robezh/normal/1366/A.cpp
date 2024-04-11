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
        ll a, b; cin >> a >> b;
        if(a * 2 <= b) cout << a << '\n';
        else if(b * 2 <= a) cout << b << '\n';
        else cout << (a + b) / 3 << '\n';
    }
}