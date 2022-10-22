#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
vector<int>g[maxn];
int f[maxn],d[maxn],L[maxn],R[maxn],fix[maxn],gt[maxn],ans=0;
int n,k;
char str[maxn];
int calc(int x){
    if (fix[x]) return gt[x]?R[x]:L[x];
    else return min(L[x],R[x]);
}
int find(int x){
  //  printf("---%d\n",x);
    if (f[x]==x) return x;
    int t=f[x]; f[x]=find(f[x]);
    d[x]^=d[t]; 
    return f[x];
}
void merge(int u,int v,int dd){ 
    int fa=find(u),fb=find(v);
    if (fa!=fb){
        ans-=calc(fa)+calc(fb);
        f[fa]=fb;
        d[fa]=d[u]^d[v]^dd;
        L[fb]+=d[fa]?R[fa]:L[fa];
        R[fb]+=d[fa]?L[fa]:R[fa];
     //   printf("==%d %d\n",L[fb],R[fb]);
        fix[fb]|=fix[fa];
        if (fix[fa]) gt[fb]=gt[fa]^d[fa];
        ans+=calc(fb);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    for (int i=1; i<=k; i++){
        int c,x;
        scanf("%d",&c);
        for (int j=1; j<=c; j++) scanf("%d",&x),g[x].push_back(i);
    }
    for (int i=1; i<=k; i++) f[i]=i,d[i]=0,L[i]=1;
    for (int i=1; i<=n; i++){
        if (str[i]=='0'){
            if (g[i].size()==1){
                int x=g[i][0];
                int c=find(x);
                ans-=calc(c);
             //   printf("-%d\n",ans);
                fix[c]=1; gt[c]=d[x];
                ans+=calc(c);
                
             //   printf("+%d\n",ans);
            }else if (g[i].size()==2){
                int x=g[i][0],y=g[i][1];
                merge(x,y,1);
            }
        }else{
            if (g[i].size()==1){
                int x=g[i][0];
                int c=find(x);
                ans-=calc(c);
                fix[c]=1; gt[c]=d[x]^1;
                ans+=calc(c);
            }else if (g[i].size()==2) {
                int x=g[i][0],y=g[i][1];
                merge(x,y,0);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}