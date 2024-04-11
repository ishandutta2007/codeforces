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

struct P {
    int l, r;
    int rem;
};

vector<pii> res;

void add(int x, int y) {
    res.push_back({x, y});
}


void solve(int l, int r) {
    if(l == r) return ;
    int len = (r - l + 1) / 2;
//    cout << l << " " << r << " " << len << endl;
    solve(l, l + len - 1);
    solve(l + len, l + 2 * len - 1);
    for(int i = 0; i < len; i++) {
        add(l + i, l + len + i);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int pw = 1;
    while(pw * 2 <= n) pw *= 2;
    solve(1, pw);
    solve(n - pw + 1, n);
    cout << res.size() << endl;
    for(auto &p : res) cout << p.first << " " << p.second << '\n';
}