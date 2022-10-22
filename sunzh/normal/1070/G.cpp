#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
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
int n,m;
int a[110],v[110];
int s[110],h[110];
bool vis[110];
int ans[110];
bool check(int x,int t){
	int pos=s[x],sum=h[x];
	if(s[x]<=t){
		for(int j=pos+1;j<=t;++j){
			sum+=v[j];if(sum<0) return 0;
		}
		return 1;
	}
	else{
		for(int j=pos-1;j>=t;--j){
			sum+=v[j];if(sum<0) return 0;
		}
		return 1;
	}
}
void finish(int x,int t){
	int pos=s[x],sum=h[x];
	if(pos<=t){
		for(int j=pos+1;j<=t;++j){
			v[j]=0;
		}
	}
	else{
		for(int j=pos-1;j>=t;--j){
			v[j]=0;
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i) s[i]=read(),h[i]=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int pos=1;pos<=n;++pos){
		for(int i=1;i<=n;++i) vis[i]=0,v[i]=a[i];
		for(int cnt=1;cnt<=m;++cnt){
			bool fl=0;
			for(int i=1;i<=m;++i){
				if(!vis[i]&&check(i,pos)){
					vis[i]=1;finish(i,pos);fl=1;ans[cnt]=i;break ;
				}
			}
			if(!fl) break ;
			if(cnt==m){
				printf("%d\n",pos);
				for(int i=1;i<=m;++i) printf("%d ",ans[i]);
				exit(0);
			}
		}
	}
	printf("-1\n");
	return 0;
}