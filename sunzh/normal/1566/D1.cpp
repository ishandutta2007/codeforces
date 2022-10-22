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
int a[100010];
int b[100010];
int ps[100010];
int L[100010],nw[100010];
int seat[100010];
int ans=0;
bool used[310][310];
void gotto(int x,int y){
	for(int i=1;i<=y;++i){
		ans+=used[x][i];
	}
	used[x][y]=1;
}
void get(int l,int r){
	for(int i=1;i<=n;++i){
		if(i*m<l) continue ;
		if(i*m<=r){
			for(int j=m;j>=1&&(i-1)*m+j>=l;--j){
				if(!used[i][j]){
					gotto(i,j);return ;
				}
			}
		}
		else{
			int R=r-((i-1)*m);
			for(int j=R;j>=1&&(i-1)*m+j>=l;--j){
				if(!used[i][j]){
					gotto(i,j);return ;
				}
			}
			break ;
		}
	}
}
int main(){
	T=read();
	while(T--){
		ans=0;
		n=read(),m=read();
		for(int i=1;i<=n*m;++i) a[i]=b[i]=read();
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) used[i][j]=0;
		sort(b+1,b+n*m+1);int c=unique(b+1,b+n*m+1)-b-1;
		for(int i=1;i<=c;++i) ps[i]=0;
		for(int i=1;i<=n*m;++i) a[i]=lower_bound(b+1,b+c+1,a[i])-b,ps[a[i]]++;
		for(int i=1;i<=c;++i) ps[i]+=ps[i-1];
		for(int i=1;i<=n*m;++i) get(ps[a[i]-1]+1,ps[a[i]]);
		printf("%d\n",ans);
	}
}