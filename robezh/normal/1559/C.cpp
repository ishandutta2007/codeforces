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
typedef vector<int> vi;

const int N = (int)1e4 + 50;

int n, a[N];

void output(int x) {
    if(x == 0) cout << n + 1 << " ";
    rep(i, 1, n + 1) {
        cout << i << " ";
        if(x == i) cout << n + 1 << " ";
    }
    cout << '\n';
}

void solve() {
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    if(a[1] == 1) {
        output(0);
        return ;
    }
    if(a[n] == 0) {
        output(n);
        return ;
    }
    rep(i, 1, n) {
        if(!a[i] && a[i + 1]) {
            output(i);
            return ;
        }
    }

    cout << -1 << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }


}