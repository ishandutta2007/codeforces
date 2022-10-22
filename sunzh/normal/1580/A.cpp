#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
char str[410][410];
int sum[410][410];
int get(int yl,int yr,int xl,int xr){
	int su=0;
	for(int i=xl+1;i<xr;++i) su+=sum[i][yr-1]-sum[i][yl];
	su+=(yr-1-yl-(sum[xr][yr-1]-sum[xr][yl]));
	for(int i=xl+1;i<xr;++i) su+=(str[i][yl]=='0')+(str[i][yr]=='0');
	return su;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) scanf("%s",str[i]+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j) sum[i][j]=sum[i][j-1]+(str[i][j]=='1');
		}
		int ans=0x7f7f7f7f;
		for(int i=1;i<=m;++i){
			for(int j=i+3;j<=m;++j){
				int nw=0x3f3f3f3f;
				for(int l=n;l>=1;--l){
					if(l+4<=n){
						nw=min(nw,get(i,j,l,l+4));
					}
					// printf("nw:%d\n",nw);
					ans=min(ans,nw+(j-i-1-(sum[l][j-1]-sum[l][i])));
					nw+=(str[l][i]=='0')+(str[l][j]=='0');
					nw+=sum[l][j-1]-sum[l][i];
				}
			}
		}
		printf("%d\n",ans);
	}
}