#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

int t[N];
vector<int> g[N];
int dp[N];
int ans = 0;
bool used[N];
int mx = -1;
int p[N];

void dfs(int v) {
    used[v] = true;
//    cout << v << ' ' << dp[v] << ' '<< p[v] << ' ' << g[p[v]].size() << endl;
    if(ans < dp[v]) {
        ans = dp[v];
        mx = v;
    }
    if(p[v] != -1 && !used[p[v]] && g[p[v]].size() == 1) {
        dp[p[v]] = dp[v] + 1;
        dfs(p[v]);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> rt;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;

//        cout << i << ' ' << p[i] << endl;

        if(p[i] != -1) {
            g[p[i]].push_back(i);
        }

        if(t[i] == 1) {
            rt.push_back(i);
            dp[i] = 1;
            used[i] = true;
        } else {
            dp[i] = -1;
        }
//        cout << p[4] << endl;
    }
//    cout << p[4] << endl;

    for(auto x : rt)
        dfs(x);
    cout << ans << endl;
    int v = mx;
    while(true) {
        cout << v + 1 << ' ';
        if(t[v] == 1)
            break;
        v = g[v][0];

    }
}