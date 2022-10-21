#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    ll res = 0;
    ll s0 = 0, s1 = 0;
    rep(i, 0, n) {
        if(i % 2 == 0) s1 += a[i];
        else s0 += a[i];
    }
    res = max(res, s1);
    rep(i, n, 2 * n) {
        s1 -= a[i - n];
        swap(s1, s0);
        s1 += a[i - n];
        res = max(res, s1);
    }
    cout << res << '\n';


}