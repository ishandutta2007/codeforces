#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;
const int k_Inf = 1e9;

int n, m;
vector<int> adjacent[k_N];
bool visited[k_N];

int a[k_N], dp[k_N];
int c[k_N];

bool is_lucky(int x){
    if(!x)
        return false;

    while(x){
        if(x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }

    return true;
}

void update_dp(int count, int multiplier){
    int x = count * multiplier;
    for(int i = n; i >= x; --i)
        dp[i] = min(dp[i], dp[i - x] + count);
}

int count_nodes_in_component(int node){
    visited[node] = true;

    int answer = 1;
    for(int to: adjacent[node]){
        if(visited[to])
            continue;

        answer += count_nodes_in_component(to);
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            a[i] = count_nodes_in_component(i);

    for(int i = 1; i <= n; ++i)
        ++c[a[i]];

    for(int i = 1; i <= n; ++i)
        dp[i] = k_Inf;
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        if(!c[i])
            continue;

        int remove = 0;
        for(int bit = 1; (2 * bit - 1) <= c[i]; bit *= 2){
            update_dp(bit, i);
            remove = 2 * bit - 1; 
        }

        c[i] -= remove;
        if(!c[i])
            continue;

        update_dp(c[i], i);
    }

    int answer = k_Inf;
    for(int i = 0; i <= n; ++i)
        if(is_lucky(i))
            answer = min(dp[i], answer);

    if(answer == k_Inf)
        answer = -1;
    else
        --answer;

    cout << answer << "\n";

    return 0;
}