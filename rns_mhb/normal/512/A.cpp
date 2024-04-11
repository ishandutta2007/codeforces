#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

#define N 105

int c[N];
char s[N][N];
vi adj[N];
stack<int> st;

bool dfs(int u) {
    c[u] = 1;
    int i, v;
    for(i = 0; i < adj[u].size(); i ++) {
        v = adj[u][i];
        if(c[v] == 1) return 0;
        if(!c[v] && !dfs(v)) return 0;
    }
    st.push(u);
    c[u] = 2;
    return 1;
}

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) scanf("%s", s[i]);
    for(i = 1; i < n; i ++) for(j = i + 1; j <= n; j ++) {
        k = 0;
        while(s[i][k] == s[j][k]) k ++;
        if(s[j][k] == 0) {puts("Impossible"); return 0;}
        if(s[i][k] == 0) continue;
        adj[s[i][k] - 'a'].pb(s[j][k] - 'a');
    }
    for(i = 25; i >= 0; i --) if(!c[i] && !dfs(i)) {puts("Impossible"); return 0;}
    while(!st.empty()) putchar(st.top() + 'a'), st.pop();
}