#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e6 + 50, M = (int)5e5 + 50;

int n, k;
bitset<M> dp;
int vis[N], to[N];
int cnt[N];

void do_knapsack(int x) {
//    cout << "Adding " << x << endl;
    dp |= (dp << x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n) cin >> to[i], to[i]--;
    rep(i, 0, n) {
        if(!vis[i]) {
            int c = 0, cur = i;
            do {
                vis[cur] = true;
                c++;
                cur = to[cur];
            } while(cur != i);
//            cout << c << endl;
            cnt[c]++;
        }
    }
    dp[0] = true;
    int sum = 0, mx = -1;
    rep(i, 0, N) {
        sum += cnt[i] * (i / 2);
    }
//    cout << sum << endl;
    if(sum >= k) mx = k * 2;
    else {
        mx = min(n, sum * 2 + (k - sum));
    }

    rep(i, 0, M) {
        if(cnt[i]) {
            for(int t = 1; t <= cnt[i]; t *= 2) {
                do_knapsack(t * i);
                cnt[i] -= t;
            }
            if(cnt[i]) do_knapsack(cnt[i] * i);
        }
    }
    int mn = (dp[(k < M ? k : n - k)] ? k : k + 1);
//    cout << dp << endl;
    cout << mn << " " << mx << endl;
}