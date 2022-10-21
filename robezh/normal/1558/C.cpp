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
const int N = (int)2050;

int a[N];
vi res;

int posn = -1, posn1 = -1;

void rev(int p) {
    reverse(a + 1, a + p + 1);
    if(posn <= p) posn = p + 1 - posn;
    if(posn1 <= p) posn1 = p + 1 - posn1;
    res.push_back(p);
}

void solve(int n) {
    posn = posn1 = -1;
    rep(i, 1, n + 1) {
        if(a[i] == n) posn = i;
        else if(a[i] == n - 1) posn1 = i;
    }
    rev(posn);
    rev(posn1 - 1);
    rev(posn1 + 1);
    rev(posn);
    rev(n);
}

void solve() {
    int n;
    cin >> n;
    res.clear();
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) {
        if(i % 2 != a[i] % 2) {
            cout << -1 << '\n';
            return ;
        }
    }
    int tn = n;
    while(n > 1) {
        solve(n);
        n -= 2;
    }
//    rep(i, 1, tn + 1) cout << a[i] << " ";
//    cout << endl;
    cout << sz(res) << '\n';
    for (int x : res) cout << x << " ";
    cout << '\n';
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