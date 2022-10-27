#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL ans = 0;

const int N=1002;
char s[N]; int n;
int vis[N][2],a[N][2];


int par[N<<2],sz[N<<2],fat[N<<2];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int find2(int x){
    return fat[x]==x?x:fat[x]=find2(fat[x]);
}
void update(int len){
    //printf("len = %d\n", len);
    memset(vis,0,sizeof(vis));
    memset(a,0,sizeof(a));
    for(int i=1;i<N<<2;i++) par[i]=i,fat[i]=i;

    queue< pair<int,int> > q;
    for(int i=1;i<=n-len;i++){ 
        q.push(make_pair(i,1)); vis[i][1]=1; a[i][1]=0;
        if(s[i]!='?' && i!=1){
            q.push(make_pair(i,0)); vis[i][0]=1; a[i][0]=s[i]-'0';
        }
    }
    q.push(make_pair(1,0)); vis[1][0]=1; a[1][0]=1;
    q.push(make_pair(n-len+1,1)); vis[n-len+1][1]=1; a[n-len+1][1]=1;

    while(q.size()) {
        pair<int,int> tmp=q.front(); q.pop();
        //printf("[%d %d]\n", tmp.first,tmp.second);
        int u=tmp.first;
        if(tmp.second == 0){
            int v1=1+n-u;
            if(v1>=1 && v1<=n && vis[v1][0]==0) {
                q.push(make_pair(v1,0)); vis[v1][0]=1; a[v1][0]=a[u][0];
            }  
            if(u<=n && u>=n-len+1 && vis[u][1]==0 && s[u]!='?') {
                q.push(make_pair(u,1)); vis[u][1]=1; a[u][1]=((s[u]-'0')^a[u][0]);
            }          
        } else {
            int v1=n+n-len+1-u;
            if(v1>=n-len+1 && v1<=n && vis[v1][1]==0) {
                q.push(make_pair(v1,1)); vis[v1][1]=1; a[v1][1]=a[u][1];
            }  
            if(u<=n && u>=1 && vis[u][0]==0 && s[u]!='?') {
                q.push(make_pair(u,0)); vis[u][0]=1; a[u][0]=((s[u]-'0')^a[u][1]);
            }  
        }
    }
    for(int i=1;i<=n;i++){
        //printf("i=%d,(%d,%d) %d %d\n", i,vis[i][0],vis[i][1],a[i][0],a[i][1]);
    }
    for(int i=1;i<=n;i++){
        int x1=i<<1;
        int x2=(n-i+1)<<1;
        if(vis[i][0]==0){
            //printf("link %d %d\n", i,n-i+1);
            fat[find2(x1)]=find2(x2);
        }
        if(find(x1<<1)==find(x2<<1|1)) return;
        if(find(x1<<1|1)==find(x2<<1)) return;
        par[find(x1<<1)]=find(x2<<1);
        par[find(x1<<1|1)]=find(x2<<1|1);
    }
    for(int i=1;i<=len;i++){
        int x1=(n-i+1)<<1|1;
        int x2=(n+n-len+1-(n-i+1))<<1|1;
        if(vis[n-i+1][1]==0){
            //printf("link %d %d\n", n-i+1,n+n-len+1-(n-i+1));
            fat[find2(x1)]=find2(x2);
        }
        if(find(x1<<1)==find(x2<<1|1)) return;
        if(find(x1<<1|1)==find(x2<<1)) return;
        par[find(x1<<1)]=find(x2<<1);
        par[find(x1<<1|1)]=find(x2<<1|1);
    }
    //printf("meow\n");
    for(int i=1;i<=n;i++){
        if(vis[i][0]) if(a[i][0]!=a[n+1-i][0]) return;
        if(vis[i][1] && i>=n-len+1) if(a[i][1]!=a[n+n-len+1-i][1]) return;
        if(vis[i][0]&&vis[i][1]){
            if((a[i][0]^a[i][1])+'0'!=s[i] && s[i]!='?') return;
            continue;
        }
        if(vis[i][0]==0 && vis[i][1]==0) {
            if(s[i]=='0'){
                int x1=i<<1;
                int x2=i<<1|1;
                fat[find2(x1)]=find2(x2);
                if(find(x1<<1)==find(x2<<1|1)) return;
                if(find(x1<<1|1)==find(x2<<1)) return;
                par[find(x1<<1)]=find(x2<<1);
                par[find(x1<<1|1)]=find(x2<<1|1);
            } 
            if(s[i]=='1'){
                int x1=i<<1;
                int x2=i<<1|1;
                fat[find2(x1)]=find2(x2);
                if(find(x1<<1)==find(x2<<1)) return;
                if(find(x1<<1|1)==find(x2<<1|1)) return;
                par[find(x1<<1|1)]=find(x2<<1);
                par[find(x1<<1)]=find(x2<<1|1);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i][0]==0 && find2(i<<1)==(i<<1)) {
            //printf("# %d %d\n", i,0);
            cnt++;
        }
        if(vis[i][1]==0 && find2(i<<1|1)==((i<<1)|1)) {
            //printf("# %d %d\n", i,1);
            cnt++;
        }
    }
    LL tmp=1;
    for(int i=1;i<=cnt;i++) tmp=tmp*2%MOD;
    ans=(ans+tmp)%MOD;
    //printf("len = %d, tmp = %lld\n", len,tmp);
}
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    //update(4); return 0;
    for(int i=1;i<=n;i++){
        update(i);
    }
    cout<<ans<<endl;
}
/*
abcabca

$.$...*...$.$
0000##$###$##
1?1?????0?11?

??
?1?
0?`

10110
10001
   11


*/