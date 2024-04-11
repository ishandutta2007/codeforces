#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
bool sumi[210][210];
int hh[210],ht[210],th[210],tt[210];
int dp[210][210];
int inf=1000000,n,m,h,t,r;
int rec(int x,int y){
	if(x+y>r) return 0;
//	if(sumi[x][y]==true) return dp[x][y]=inf;
	if(dp[x][y]>=0) return dp[x][y];
	sumi[x][y]=true;int i,ret=1;
	for(i=1;i<=n && i<=x;i++){
		int nx=x-i+hh[i],ny=y+ht[i];
		if(nx+ny>r) continue;
		if(sumi[nx][ny]){sumi[x][y]=false;return dp[x][y]=inf;}
		ret=max(ret,1+rec(nx,ny));
	}
	for(i=1;i<=m && i<=y;i++){
		int nx=x+th[i],ny=y-i+tt[i];
		if(nx+ny>r) continue;
		if(sumi[nx][ny]){sumi[x][y]=false;return dp[x][y]=inf;}
		ret=max(ret,1+rec(nx,ny));
	}
//	cout<<x<<' '<<y<<' '<<ret<<endl;
	sumi[x][y]=false;return dp[x][y]=ret;
}
int main()
{
	int i,j,k;
	for(i=0;i<210;i++) hh[i]=ht[i]=th[i]=tt[i]=0;
	scanf("%d %d %d",&h,&t,&r);
	scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d %d",&hh[i],&ht[i]);
	scanf("%d",&m);for(i=1;i<=m;i++) scanf("%d %d",&th[i],&tt[i]);
	memset(sumi,false,sizeof(sumi));memset(dp,0,sizeof(dp));
	vector <pint> now,next,cl;now.pb(mp(h,t));sumi[h][t]=true;
	for(i=1;;i++){
		for(j=0;j<now.size();j++){
			int x=now[j].fi,y=now[j].se;
			for(k=1;k<=n && k<=x;k++){
				int nx=x-k+hh[k],ny=y+ht[k];
				if(nx+ny>r) continue;
				if(nx+ny<1){cout<<"Ivan"<<endl;cout<<i<<endl;return 0;}
				if(!sumi[nx][ny]){next.pb(mp(nx,ny));sumi[nx][ny]=true;}
			}
			for(k=1;k<=m && k<=y;k++){
				int nx=x+th[k],ny=y-k+tt[k];
				if(nx+ny>r) continue;
				if(nx+ny<1){cout<<"Ivan"<<endl;cout<<i<<endl;return 0;}
				if(!sumi[nx][ny]){next.pb(mp(nx,ny));sumi[nx][ny]=true;}
			}
		}
		now=next;next=cl;
		if(now.size()<1) break;
	}
	memset(sumi,false,sizeof(sumi));for(i=0;i<210;i++) for(j=0;j<210;j++) dp[i][j]=-1;
	int ret=rec(h,t);if(ret>=inf) cout<<"Draw"<<endl;else{cout<<"Zmey"<<endl;cout<<ret<<endl;}
	return 0;
}