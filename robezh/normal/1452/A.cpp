#include <bits/stdc++.h>
#include<bits/extc++.h>

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
        int x, y; cin >> x >> y;
        if(x == y) cout << 2 * x << '\n';
        else cout << 2 * max(x, y) - 1 << '\n';
    }
}