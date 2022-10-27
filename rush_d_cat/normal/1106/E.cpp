
 #include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
const LL INF = 1e16;
int n,m,k;
int s[N],t[N],d[N],w[N];
LL dp[N][202];

pair<int,int> nod[N<<2], lz[N<<2];

void pushdown(int rt) {
    if(lz[rt] != make_pair(0,0)) {
        lz[rt<<1] = max(lz[rt<<1], lz[rt]);
        nod[rt<<1] = max(nod[rt<<1], lz[rt]);
        lz[rt<<1|1] = max(lz[rt<<1|1], lz[rt]);
        nod[rt<<1|1] = max(nod[rt<<1|1], lz[rt]);
        lz[rt] = make_pair(0,0);
        return;
    }
}

void update(int l,int r,int rt,int L,int R,pair<int,int> p) {
    if(L<=l&&r<=R) {
        nod[rt] = max(nod[rt], p); 
        lz[rt] = max(lz[rt], p);
        return;
    }
    pushdown(rt); int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R,p);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,p);
    nod[rt] = max(nod[rt<<1], nod[rt<<1|1]);
}
pair<int,int> query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return nod[rt];
    pushdown(rt); int mid=(l+r)>>1;
    pair<int,int> ans=make_pair(0,0);
    if(L<=mid) ans=max(ans,query(l,mid,rt<<1,L,R));
    if(R >mid) ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=1;i<=k;i++) {
        scanf("%d%d%d%d",&s[i],&t[i],&d[i],&w[i]);
        update(1,n,1,s[i],t[i],make_pair(w[i],d[i]));
    }

    for(int i=0;i<=n;i++) 
        for(int j=0;j<=m;j++) 
            dp[i][j]=INF;
    
    dp[0][0]=0;

    for(int i=0;i<n;i++){
        pair<int,int> tmp = query(1,n,1,i+1,i+1);
        for(int j=0;j<m;j++){
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
        }
        if(tmp!=make_pair(0,0)) {
            for(int j=0;j<=m;j++) {
                dp[tmp.second][j] = min(dp[tmp.second][j], dp[i][j] + tmp.first);
            }
        } else {
            for(int j=0;j<=m;j++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]); 
            }
        }
    }
    LL ret = INF;
    for(int i=0;i<=m;i++) ret=min(ret, dp[n][i]);
    cout << ret << endl;
}