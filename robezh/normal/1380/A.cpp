#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1005;

int n;
int a[N];
pii pmin[N], smin[N];

void solve() {
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    pmin[0] = {a[0], 0};
    rep(i, 1, n) pmin[i] = min(pmin[i - 1], {a[i], i});
    smin[n - 1] = {a[n - 1], n - 1};
    for(int i = n - 2; i >= 0; i--) smin[i] = min(smin[i + 1], {a[i], i});
    rep(i, 1, n - 1) {
        if(a[i] > pmin[i - 1].first && a[i] > smin[i + 1].first) {
            cout << "YES\n";
            cout << pmin[i - 1].second + 1 << " " << i + 1 << " " << smin[i + 1].second + 1 << '\n';
            return ;
        }
    }
    cout << "NO\n";
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