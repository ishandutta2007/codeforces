#include<stdio.h>
int fa[400000];
int cnt[400000][2];
int fc[400000];
int n,m;
int getfa(int x){
if(x==fa[x]) return x;
int v=getfa(fa[x]);
fc[x]^=fc[fa[x]];
return fa[x]=v;
}
int main(){
scanf("%d%d",&n,&m);
for(int i=1;i<=n;++i) fa[i]=i,fc[i]=0;
while(m--){
int a,b;
scanf("%d%d",&a,&b);
int g=getfa(a),h=getfa(b);
if(g==h){
if(fc[a]==fc[b]){
printf("0 1\n");
return 0;
}
}
else{
fa[h]=g,fc[h]=fc[a]^fc[b]^1;
}
}
for(int i=1;i<=n;++i){
getfa(i);
cnt[fa[i]][fc[i]]++;
}
long long ans1=0,ans2=0;
for(int i=1;i<=n;++i){
if(cnt[i][0]>1){
ans2+=cnt[i][0]*(cnt[i][0]-1LL)/2;
}
if(cnt[i][1]>1){
ans2+=cnt[i][1]*(cnt[i][1]-1LL)/2;
}
if(cnt[i][0]&&cnt[i][1]) ans1+=n-2;
}
if(ans2) printf("1 %I64d\n",ans2);
else if(ans1) printf("2 %I64d\n",ans1);
else printf("3 %I64d\n",n*(n-1LL)*(n-2LL)/6);
return 0;
}