#include<bits/stdc++.h>
using namespace std;

const int N=200100;
struct edge{
	int nxt,to;
}e[N<<1];
int ft[N],a[N],s[N],n,cur,tim1,tim2,c1[(1<<20)+5],tt1[(1<<20)+5],c2[(1<<20)+5],tt2[(1<<20)+5];
long long b[N];
bool del[N];
char ch[N];
int getcen(int x,int fa){
	s[x]=1;int ans=x;
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa&&!del[e[i].to]){
		int y=e[i].to;
		int t=getcen(y,x);s[x]+=s[y];
		if(s[y]*2>=cur)ans=t;
	}
	return ans;
}
void dfs0(int x,int fa,int now){
//	printf("%d ",now);
	if(tt1[now]!=tim1){
		tt1[now]=tim1;
		c1[now]=1;
	}else c1[now]++;
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa&&!del[e[i].to]){
		dfs0(e[i].to,x,now^1<<a[e[i].to]);
	}
}
long long ans;
void dfs1(int x,int fa,int now){
	if(!now||(now&-now)==now)ans++;
	if(tt2[now]!=tim2){
		tt2[now]=tim2;
		c2[now]=1;
	}else c2[now]++;
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa&&!del[e[i].to]){
		dfs1(e[i].to,x,now^1<<a[e[i].to]);
	}
}
int cnt(int x){
	if(tt1[x]!=tim1)return 0;
	if(tt2[x]!=tim2)return c1[x];
	return c1[x]-c2[x];
}
long long dfs2(int x,int fa,int now){
	long long ans=0;
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa&&!del[e[i].to]){
		ans=(ans+dfs2(e[i].to,x,now^1<<a[e[i].to]));
	}
	ans+=cnt(now);
	for(int i=0;i<20;i++)ans+=cnt(now^1<<i);
	b[x]=(b[x]+ans);
	return ans;
}
void solve(int rt){
	int c=getcen(rt,0);
	tim1++;
	dfs0(c,0,1<<a[c]);
	ans=0;
	for(int i=ft[c];i;i=e[i].nxt)if(!del[e[i].to]){
		tim2++;
		dfs1(e[i].to,c,1<<a[c]^1<<a[e[i].to]);
		ans=(ans+dfs2(e[i].to,c,1<<a[e[i].to]));
	}
	ans=ans/2;
	b[c]=(b[c]+ans);
	del[c]=1;
	for(int i=ft[c];i;i=e[i].nxt)if(!del[e[i].to]){
		cur=s[e[i].to];
		solve(e[i].to);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[i<<1]=(edge){ft[x],y};ft[x]=i<<1;
		e[i<<1|1]=(edge){ft[y],x};ft[y]=i<<1|1;
	}
	scanf("%s",ch);
	for(int i=1;i<=n;i++)a[i]=ch[i-1]-'a';
	cur=n;solve(1);
	for(int i=1;i<=n;i++)printf("%I64d ",b[i]+1);printf("\n");
	return 0;
}