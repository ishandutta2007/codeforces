#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

long double dp[105000][10];
l_l from[105000][10];
ll N, D;
ll B[105000];
const long double EPS = 1e-12;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> D;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j <= N; j++) {
            dp[j][i] = -INF;
            from[j][i] = {-1, -1};
        }
    }
    dp[0][1] = 0;
    for(int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        B[i] = A;
        for(int j = 0; j < 10; j++) {
            if(dp[i][j] < 0) continue;
            if(chmax(dp[i+1][j], dp[i][j])) {
                from[i+1][j] = from[i][j];
            }
            ll k = (j * A) % 10;
            if(chmax(dp[i+1][k], dp[i][j] + log(A))) {
                from[i+1][k] = {i, j};
            }
        }
    }
    if(dp[N][D] < -EPS) {
        cout << -1 << endl;
        return 0;
    }
    if(abs(dp[N][D]) < EPS) {
        for(int i = 0; i < N; i++) {
            if(B[i] == 1) {
                cout << 1 << endl;
                cout << 1 << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }
    ll idx = N;
    ll d = D;
    vector<ll> ans;
    while(true) {
        if(from[idx][d].first == -1) break;
        ll nidx = from[idx][d].first;
        ll nd = from[idx][d].second;
        ans.push_back(B[nidx]);
        idx = nidx;
        d = nd;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}