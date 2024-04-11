#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
int a[N];

void solve() {

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    ll sum = 0;
    multiset<ll> S;
    rep(i, 0, n) sum += a[i], S.insert(a[i]);
    priority_queue<ll> pque;
    pque.push(sum);

    while(!pque.empty()) {
        if(sz(pque) > sz(S)) {
            return cout << "NO\n", void();
        }
        ll cur = pque.top(); pque.pop();
        auto it = S.find(cur);
        if(it != S.end()) {
            S.erase(it);
        } else if(cur == 1) {
            return cout << "NO\n", void();
        } else {
            pque.push(cur / 2);
            pque.push((cur + 1) / 2);
        }
    }
    cout << "YES\n";

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