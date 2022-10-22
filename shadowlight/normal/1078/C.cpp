#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 998244353;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 3e5 + 7;

vector <vector <ll> > dp;

vector <ll> st;
vector <vector <ll> > gr;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

void init() {
    st.resize(N, 0);
    st[0] = 1;
    for (ll i = 1; i < N; i++) {
        st[i] = st[i - 1] * 2 % INF;
    }
}

void dfs(ll v, ll p) {
    ll sons = 0;
    ll val = 1;
    ll all = 1;
    dp[v][0] = 0;
    ll val1 = 1;
    for (ll u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
        val = val * (dp[u][0] + dp[u][2] * rev(2) % INF) % INF;
        val1 = val1 * (dp[u][0] + dp[u][2]) % INF;
        sons++;
    }
    dp[v][1] = st[sons] * val % INF;
    dp[v][2] = val1;
    for (ll u : gr[v]) {
        if (u == p) continue;
        dp[v][0] += val * rev((dp[u][0] + dp[u][2] * rev(2) % INF) % INF) % INF * dp[u][1] % INF * st[sons - 1] % INF;
        dp[v][0] %= INF;
    }
    //cout << v << " " << dp[v][0] << " " << dp[v][1] << " " << dp[v][2] << "\n";
}


int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    init();
    int n;
    cin >> n;
    dp.resize(n, vector <ll> (3, 0));
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0, -1);
    cout << (dp[0][2] + dp[0][0]) % INF << "\n";
}