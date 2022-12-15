#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5 + 7;
const long long LOGN = 20;
long long n, m;
array<long long, 2> p[MAXN], queries[MAXN];
vector<int> adj[MAXN];
int par[MAXN], lca[MAXN][LOGN], lvl[MAXN];

long long area(array<long long, 2> a, array<long long, 2> b, array<long long, 2> c){
    return (a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[0] * c[1] - b[0] * a[1] - c[0] * b[1]);
}

void build_tree(){
    stack<int> st;

    st.push(n);
    st.push(n - 1);
    par[n - 1] = n;
    adj[n].push_back(n - 1);
    par[n] = n;

    for(int i = n - 2; i >= 1; --i){
        int pr1 = st.top();
        st.pop();
        int pr2 = st.top();
        st.pop();

        while(area(p[pr1], p[i], p[pr2]) < 0){
            pr1 = pr2;
            if(st.empty()){
                pr2 = -1;
                break;
            }
            pr2 = st.top();
            st.pop();
        }
        if(pr2 != -1)
            st.push(pr2);
        st.push(pr1);
        st.push(i);

        adj[pr1].push_back(i);
        par[i] = pr1;
    }
}

void dfs(int u, int level = 0){
    lvl[u] = level;
    for(int to: adj[u]){
        dfs(to, level + 1);
    }
}

void build_lca(){
    for(int i = 1; i <= n; ++i){
        lca[i][0] = par[i];
    }
    for(int j = 1; j < LOGN; ++j){
        for(int i = 1; i <= n; ++i){
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }

    dfs(n);
}

int find_lca(int u, int v){
    if(lvl[u] < lvl[v])
        swap(u, v);

    int diff = lvl[u] - lvl[v];
    for(int i = LOGN - 1; i >= 0; --i){
        if(diff & (1 << i))
            u = lca[u][i];
    }
    if(u == v)
        return u;

    for(int i = LOGN - 1; i >= 0; --i){
        if(lca[u][i] != lca[v][i]){
            u = lca[u][i];
            v = lca[v][i];
        }
    }

    u = par[u];
    return u;
}

void solve(){
    if(n == 1){
        for(int i = 1; i <= m; ++i)
            cout << "1\n";
        return;
    }

    build_tree();
    build_lca();

    for(int i = 1; i <= m; ++i){
        cout << find_lca(queries[i][0], queries[i][1]) << "\n";
    }
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> p[i][0] >> p[i][1];
    }

    cin >> m;
    for(int i = 1; i <= m; ++i){
        cin >> queries[i][0] >> queries[i][1];
    }
}

int main(){
    read();
    solve();
}