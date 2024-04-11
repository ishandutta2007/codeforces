#include <bits/stdc++.h>

const int max_N = (int)2e5 + 21;
const int log_N = (int)log2(max_N) + 1;

int bit[max_N], check[max_N];

int n, m, q, u[max_N], v[max_N], ans[max_N];

int p[log_N][max_N], _p[log_N][max_N], dep[max_N], _dep[max_N];

int dfn[max_N], _dfn[max_N], cnt;

std::vector<int> vec[max_N];

std::vector<std::pair<int, int>> _vec[max_N];

void dfs_pre(int x){
    dfn[x] = ++ cnt;
    for(int i=1;i<log_N;++i){
        p[i][x] = p[i-1][p[i-1][x]];
    }
    for(auto&y:vec[x]){
        dep[y] = dep[x] + 1;
        dfs_pre(y);
    }
    _dfn[x] = cnt;
}

int lca(int x, int y){
    if(dep[x] > dep[y]) std::swap(x, y);
    int k = dep[y]-dep[x];
    for(int i=0;k;++i,k>>=1)
        if(k&1) y = p[i][y];
    if(x == y) return x;
    for(int i=log_N-1;~i;--i)
        if(p[i][x] != p[i][y]){
            x = p[i][x];
            y = p[i][y];
        }
    return p[0][x];
}

void update_low(int x, int y){
    if(dep[_p[0][x]] > dep[y]) _p[0][x] = y;
}

int last(int x, int y){
    if(x == y) return x;
    for(int i=log_N-1;~i;--i)
        if(dep[_p[i][x]] > dep[y]){
            x = _p[i][x];
        }
    if(dep[_p[0][x]] > dep[y]) return -1;
    return x;
}

int main(){
    scanf("%d", &n);
    for(int i=2;i<=n;++i){
        scanf("%d", p[0]+i);
        vec[p[0][i]].push_back(i);
    }
    dfs_pre(1);

    for(int i=1;i<=n;++i) _p[0][i] = i;
    scanf("%d", &m);
    for(int i=1;i<=m;++i){
        scanf("%d%d", u+i, v+i);
        if(dfn[u[i]] > dfn[v[i]]) std::swap(u[i], v[i]);
        _vec[dfn[u[i]]].push_back({0, dfn[v[i]]});
        int w = lca(u[i], v[i]);
        update_low(u[i], w), update_low(v[i], w);
    }
    for(int i=n;i>1;--i) update_low(p[0][i], _p[0][i]);
    for(int i=1;i<=n;++i) _dep[i] = _dep[_p[0][i]] + 1;
    for(int i=1;i<log_N;++i)
        for(int j=1;j<=n;++j) _p[i][j] = _p[i-1][_p[i-1][j]];

    scanf("%d", &q);
    for(int i=1,a,b,c;i<=q;++i){
        scanf("%d%d", &a, &b);
        if(a == b){ ans[i] = 0; continue; }
        c = lca(a, b);
        int x = last(a, c), y = last(b, c);
        if(x==-1 || y==-1){ ans[i] = -1; continue; }
        ans[i] += (_dep[a]-_dep[x]); if(x != c) ++ ans[i];
        ans[i] += (_dep[b]-_dep[y]); if(y != c) ++ ans[i];
        if(x != c && y != c){
            if(dfn[x] > dfn[y]) std::swap(x, y);
            _vec[dfn[x]-1].push_back({i, dfn[y]-1});
            _vec[dfn[x]-1].push_back({-i, _dfn[y]});
            _vec[_dfn[x]].push_back({-i, dfn[y]-1});
            _vec[_dfn[x]].push_back({i, _dfn[y]});
        }
    }

    for(int i=1;i<=n;++i)
        for(auto&pair:_vec[i]){
            if(!pair.first){
                for(int x=pair.second;x<=n;x+=x&-x) ++ bit[x];
            }
            else{
                int f = 1, id = pair.first;
                if(id < 0) f = -1, id = -id;
                for(int x=pair.second;x;x-=x&-x) check[id] += f*bit[x];
            }
        }

    for(int i=1;i<=q;++i){
        if(check[i]) -- ans[i];
        printf("%d\n", ans[i]);
    }

    return 0;
}