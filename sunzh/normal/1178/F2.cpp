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
int cnt;
int a[1000010];
int lf[510],rg[510];
int f[1010][1010];
const int mod=998244353;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int x=read();if(x!=a[cnt]) a[++cnt]=x;
	}
	if(cnt>2*n){
		printf("%d\n",0);
		return 0;
	}
	memset(lf,0x3f,sizeof(lf));
	for(int i=1;i<=cnt;++i) lf[a[i]]=min(lf[a[i]],i),rg[a[i]]=max(rg[a[i]],i);
	for(int i=1;i<=cnt;++i) if(lf[a[i]]==i&&rg[a[i]]==i) f[i][i]=1;
	for(int i=0;i<=cnt;++i) f[i+1][i]=1;
	for(int len=2;len<=cnt;++len){
		for(int i=1;i<=cnt;++i){
			int j=i+len-1;if(j>cnt) break ;
			int k=0x3f3f3f3f3f;
			for(int l=i;l<=j;++l) k=min(k,a[l]);
			if(lf[k]<i||rg[k]>j) continue ;
			int x=lf[k],y=rg[k];
			long long s1=0ll,s2=0ll;
			for(int l=i;l<=x;++l) (s1+=1ll*f[i][l-1]*f[l][x-1])%=mod;
			for(int l=y;l<=j;++l) (s2+=1ll*f[y+1][l]*f[l+1][j])%=mod;
//			if(y==j) s2=1;if(x==i) s1=1;
			f[i][j]=1ll*s1*s2%mod;
			int pre=-1;
			for(int l=i;l<=j;++l){
				if(a[l]==k){
					if(pre!=-1){
						f[i][j]=1ll*f[i][j]*f[pre+1][l-1]%mod;
					}
					pre=l;
				}
			}
		}
	}
	printf("%d\n",f[1][cnt]);
	return 0;
}