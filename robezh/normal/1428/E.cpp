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
const int N = (int)1e5 + 50;


int n, k;
int a[N];
int ct[N];
ll res = 0;

ll get(int x, int k) {
    ll s = x / k;
    int c1 = x % k, c0 = k - c1;
    return c0 * s * s + c1 * (s + 1) * (s + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> k;
    priority_queue<pll> pque;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        res += 1LL * a[i] * a[i];
        ct[i] = 1;
        if(a[i] > 1) {
            pque.push({get(a[i], 1) - get(a[i], 2), i});
        }
    }
    while(k > n) {
        auto p = pque.top(); pque.pop();
        res -= p.first;
        k--;
        ct[p.second]++;
        if(ct[p.second] < a[p.second]) {
            pque.push({get(a[p.second], ct[p.second]) - get(a[p.second], ct[p.second] + 1), p.second});
        }
    }
    cout << res << '\n';
}