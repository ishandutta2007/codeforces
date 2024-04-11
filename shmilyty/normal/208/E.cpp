#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 1000003;
int n, m, U[N], K[N], head[N], to[N], nxt[N], fa[N], wson[N], len[N], dep[N], sta[N], top, ans[N];
int tot, headq[N], k[N], id[N], nxtq[N];
inline void add(int a, int b){
    static int cnt = 0;
    to[++ cnt] = b; nxt[cnt] = head[a]; head[a] = cnt;
}
inline void addq(int u, int _k, int _id){
    k[++ tot] = _k; id[tot] = _id; nxtq[tot] = headq[u]; headq[u] = tot;
}
inline void dfs(int x){
    sta[++ top] = x;
    dep[x] = dep[fa[x]] + 1;
    for(Rint i = headq[x];i;i = nxtq[i])
        ans[id[i]] = (top > k[i]) ? sta[top - k[i]] : 0;
    for(Rint i = head[x];i;i = nxt[i]){
        dfs(to[i]);
        if(len[to[i]] > len[wson[x]]) wson[x] = to[i];
    }
    len[x] = len[wson[x]] + 1;
    -- top;
}
int tmp[N], *now = tmp, *dp[N];
inline void calc(int x){
    dp[x][0] = 1;
    if(wson[x]){
        dp[wson[x]] = dp[x] + 1; calc(wson[x]);
        for(Rint i = head[x];i;i = nxt[i])
            if(to[i] != wson[x]){
                dp[to[i]] = now; now += len[to[i]];
                calc(to[i]);
                for(Rint j = 1;j <= len[to[i]];j ++) dp[x][j] += dp[to[i]][j - 1];
            }
        for(Rint i = headq[x];i;i = nxtq[i])
            ans[id[i]] = dp[x][k[i]];
    }
}
int main(){
    scanf("%d", &n);
    for(Rint i = 1;i <= n;i ++){
        scanf("%d", fa + i);
        if(fa[i]) add(fa[i], i);
    }
    scanf("%d", &m);
    for(Rint i = 1;i <= m;i ++)
	{
        scanf("%d%d", U + i, K + i);
        addq(U[i], K[i], i);
    }
    for(Rint i = 1;i <= n;i ++)
    	if(!fa[i]) 
			dfs(i);
    memset(headq, 0, sizeof headq); 
	tot = 0;
    for(Rint i = 1;i <= m;i ++)
        if(ans[i]) 
			addq(ans[i], K[i], i);
    memset(ans, 0, sizeof ans);
    for(Rint i = 1;i <= n;i ++)
    	if(!fa[i])
		{
    		dp[i] = now; 
			now += len[i];
    		calc(i);
    	}
    for(Rint i = 1;i <= m;i ++) printf("%d ", max(ans[i] - 1, 0));
}