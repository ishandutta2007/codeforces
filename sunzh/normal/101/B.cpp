#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,m,cnt;
int ans;
map<int,int>mp;
int a[200010],f[200010];
int s[100010],t[100010];
struct node{
	int s,t;
}b[100010];
const int mod=1e9+7;
bool cmp(node x,node y){
	return x.t<y.t;
}
signed main(){
	n=read(),m=read();
	a[++cnt]=0;
	for(int i=1;i<=m;++i) a[++cnt]=s[i]=read(),a[++cnt]=t[i]=read();
	a[++cnt]=n;
	sort(a+1,a+cnt+1);
	int len=unique(a+1,a+cnt+1)-a;
	for(int i=1;i<len;++i) mp[a[i]]=i;
	for(int i=1;i<=m;++i) b[i].s=mp[s[i]],b[i].t=mp[t[i]];
	sort(b+1,b+m+1,cmp);
	f[1]=1;
	int p=1;
	for(int i=1;i<=m;++i){
		while(p<b[i].t){
			f[p]+=f[p-1];if(f[p]>mod) f[p]-=mod; ++p;
		}
		f[b[i].t]+=(f[b[i].t-1]-f[b[i].s-1]<0?f[b[i].t-1]-f[b[i].s-1]+mod:f[b[i].t-1]-f[b[i].s-1]);
		if(f[b[i].t]>mod) f[b[i].t]-=mod;
	}
	printf("%d\n",f[len-1]%mod);
	return 0;
}