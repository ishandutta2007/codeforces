#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int N = (int)2e5 + 50;

ll a[N];

int n;
ll k, x;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> k >> x;
    vector<ll> vs;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    rep(i, 0, n - 1) vs.push_back(a[i + 1] - a[i]);
    sort(all(vs));
    int gp = n;
    for(ll len : vs) {
        ll tk = max(0LL, (len + x - 1) / x - 1);
        if(tk <= k) {
            k -= tk;
            gp--;
        }
    }
    cout << gp << endl;
}