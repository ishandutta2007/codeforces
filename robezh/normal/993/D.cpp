#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const int N = 55;
const ll INF = (ll)1e18;

int n;
P p[N];
ll val[N];
ll dp[N][N];

bool check(ll x) {
    for(int i = 1; i <= n; i++) val[i] = p[i].first - p[i].second * x;

    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    int r = 1;
    for(int i = 1; i <= n; ) {
        while(r <= n && p[r].first == p[i].first) r++;
        vector<ll> psum;
        psum.push_back(0);
        ll s = 0;
        for(int j = i; j < r; j++){
            s += val[j];
            psum.push_back(s);
        }
        for(int j = 0; j <= n; j++) {
            if(dp[i-1][j] == INF) continue;
            for(int k = 0; k <= r - i; k++) {
                int left = k, right = r - i - k;
                int dif = left - right;
                if(j >= r - i - k)
                    dp[r-1][j + dif] = min(dp[r-1][j + dif], dp[i-1][j] + psum[k]);
            }
        }
        i = r;
    }
    for(int j = 0; j <= n; j++) if(dp[n][j] <= 0) return true;
    return false;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].first, p[i].first *= 1000;
    for(int i = 1; i <= n; i++) cin >> p[i].second;
    sort(p + 1, p + n + 1, greater<>());

    ll l = 0, r = (ll)1e11, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;

    }
    cout << r << endl;
}