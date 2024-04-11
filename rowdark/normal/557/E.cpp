#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int fa[5001][5001];
int cnt[5001][5001];
int order[5001];
char s[6001];
int invorder[5001];
inline int cmp(const int x,const int y){
return strcmp(s + x, s + y) < 0;
}
int M;
int N;
int main(){
scanf("%s",s);
scanf("%d",&M);
N=strlen(s);
for(int i=0;i<N;++i) order[i]=i;
for(int i=0;i<N;++i) for(int j=0;j<N;++j) fa[i][j]=j;
sort(order,order+N,cmp);
for(int i=0;i<N;++i) invorder[order[i]]=i;
for(int i=1;i<N;++i){
int f=0;
while(s[order[i-1]+f]==s[order[i]+f]) fa[f][i]=fa[f][i-1],++f;
}
for(int i=0;i<N;++i){
{
int st=i,ed=i,len=0;
while(st>=0&&ed<N&&s[st]==s[ed]){
++cnt[fa[len][invorder[st]]][len];
len+=4;
st-=2;
ed+=2;
}
}

{
int st=i-1,ed=i+1,len=2;
while(st>=0&&ed<N&&s[st]==s[ed]){
++cnt[fa[len][invorder[st]]][len];
len+=4;
st-=2;
ed+=2;
}
}

{
int st=i,ed=i+1,len=1;
while(st>=0&&ed<N&&s[st]==s[ed]){
++cnt[fa[len][invorder[st]]][len];
len+=4;
st-=2;
ed+=2;
}
}

{
int st=i-1,ed=i+2,len=3;
while(st>=0&&ed<N&&s[st]==s[ed]){
++cnt[fa[len][invorder[st]]][len];
len+=4;
st-=2;
ed+=2;
}
}

}
for(int i=0;i<N;++i) for(int j=0;j<N;++j)
if(cnt[i][j]>=M){
s[order[i]+j+1]=0;
printf("%s\n",s+order[i]);
return 0;
}
else M-=cnt[i][j];
return 0;
}