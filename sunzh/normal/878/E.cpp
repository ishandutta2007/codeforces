#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=1e9+7;
int n,q;
int a[100010],b[100010];
int sum[100010];
int pre[100010];
int fa[100010],f[100010];
struct node{
	int l,r,id;
	inline bool operator <(const node &x)const {
		return r<x.r;
	}
}Q[100010];
int pw[100010];
int ans[100010];
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
inline int cut(int x,int y){
//	printf("x:%d,y:%d,bx:%d,by+1:%d\n",x,y,b[x],b[y+1]);
	return (b[x]-b[y+1]*pw[y-x+1]%mod+mod)%mod;
} 
void add(int x,int y){
	f[y]=f[x],fa[find(x)]=find(y);
	if((x-f[x]>30&&sum[y]>0)||sum[x]+(sum[y]<<x-f[x])>mod) sum[y]=mod;
	else sum[y]=sum[x]+(sum[y]<<x-f[x]);
}
signed main(){
	n=read(),q=read();
	pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=n;++i) sum[i]=a[i]=read(),fa[i]=i,f[i]=i-1;
	for(int i=n;i>=1;--i) b[i]=(a[i]+b[i+1]*2ll)%mod;
	for(int i=1;i<=q;++i) Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
	sort(Q+1,Q+q+1);
	int pos=1;
	for(int i=1;i<=n;++i){
		while(sum[fa[i]]>=0&&f[i]) add(f[i],fa[i]);
		pre[i]=(pre[f[i]]+(cut(f[i]+1,i)*2)%mod)%mod;
//		printf("i:%d,pre:%d\n",i,pre[i]);
		while(pos<=q&&Q[pos].r==i){
//			printf("i:%d,pos:%d,id:%d,l:%d\n",i,pos,Q[pos].id,Q[pos].l);
			int x=find(Q[pos].l);
//			printf("x:%d\n",x);
			ans[Q[pos].id]=(pre[i]-pre[x]+cut(Q[pos].l,x)+mod)%mod;
			++pos;
		}
	}
	for(int i=1;i<=q;++i){
		printf("%d\n",(ans[i]+mod)%mod);
	}
	return 0;
}