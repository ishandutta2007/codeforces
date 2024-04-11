#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=5010;
int n,k,v,cnt;
vector<int> lis[maxn];
int a[maxn],c[maxn],w[maxn],t[maxn],vis[maxn];
struct point{
    int x,y,z;
}ans[50100];
int main(){
    scanf("%d%d%d",&n,&k,&v);
    for (int i=1; i<=n; i++) scanf("%d",&c[i]),a[i]=c[i]%k;
    w[0]=1;
    for (int i=1; i<=n; i++){
        memcpy(t,w,sizeof(t));
        for (int j=0; j<k; j++){
            int p=(j+a[i])%k;
            if (t[j] && !w[p]){
                w[p]=1;
                lis[p]=lis[j];
                lis[p].push_back(i);
            }
        }
    }
    if (w[v%k]){
        int p=v%k,x,z;
        if (!p){
            x=1;
            z=2;
        }else{
            for (auto i:lis[p]) vis[i]=1;
            x=lis[p][0];
            z=(x==1)?2:1;
        }
        for (int i=1; i<=n; i++)
            if (vis[i] && i!=x) ans[cnt++]={c[i]/k+1,i,x},c[x]+=c[i],c[i]=0;
            else if (!vis[i] && i!=z) ans[cnt++]={c[i]/k+1,i,z},c[z]+=c[i],c[i]=0;
        if (c[x]>v){
            ans[cnt++]={(c[x]-v)/k,x,z};
        }else{
            int need=(v-c[x])/k;
            if (c[z]/k<need){
                puts("NO");
                return 0;
            }
            if (need) ans[cnt++]={need,z,x};
        }
        puts("YES");
        for (int i=0; i<cnt; i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
    }else{
        puts("NO");
    }
    return 0;
}