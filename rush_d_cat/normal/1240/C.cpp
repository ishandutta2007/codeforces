#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 500000 + 10;
typedef long long LL;
int T, n, k;
LL dp[N][2];
bool cmp(LL x, LL y) {
    return x > y;
}
vector< pair<int,int> > g[N];
void dfs(int u, int p) {
    for (auto e: g[u]) {
        int v = e.first; 
        if (v == p) continue;
        dfs(v, u);
    }

    dp[u][0] = dp[u][1] = 0;
    LL sum = 0;
    
    set< pair<LL,int> > st;
    for (auto e: g[u]) {
        int v = e.first;
        if (v == p) continue;
        sum += dp[v][0]; 
        st.insert( make_pair(dp[v][1] - dp[v][0] + e.second, v) );
    }

    dp[u][0] = dp[u][1] = sum;
    for (int i = 1; i <= k-1; i ++) {
        if (st.size() == 0) break;
        pair<LL,int> tmp = *st.rbegin();
        st.erase(tmp);
        if (tmp.first >= 0) {
            dp[u][0] += tmp.first;
            dp[u][1] += tmp.first;
        }   
    }
    if (st.size()) {
        pair<LL,int> tmp = *st.rbegin();
        // printf("%d %d\n", tmp.first, tmp.second);
        st.erase(tmp);
        if (tmp.first >= 0) {
            dp[u][0] += tmp.first;
            // dp[u][1] += sum;
        }           
    }   
    // printf("u = %d (%lld, %lld)\n", u, dp[u][0], dp[u][1]);
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++) {
            g[i].clear();
        }
        for (int i = 1; i < n; i ++) {
            int u, v, w; 
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
        dfs(1, 1);
        printf("%lld\n", max(dp[1][1], dp[1][0]));
    }
}