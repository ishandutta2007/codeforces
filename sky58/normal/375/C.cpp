#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[22][22][270];
int tx[10],ty[10],tv[10];
vector<tint> now,next,cl;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
string ma[22];
void aedge(int di,int x,int y,int mask){
	if(dp[x][y][mask]<=di) return;
	dp[x][y][mask]=di;
	next.pb(mp(mp(x,y),mask));
	return;
}
int main()
{
	int sx,sy,h,w,inf=1000000000,n=0,m;
	rep(i,22) rep(j,22) rep(l,270) dp[i][j][l]=inf;
	cin>>h>>w;
	rep(i,h) cin>>ma[i];
	rep(i,h) rep(j,w){
		if(ma[i][j]=='S'){sx=i;sy=j;}
		//if(ma[i][j]=='B'){bx=i;by=j;}
		if(ma[i][j]>='1' && ma[i][j]<='8'){
			int t=(ma[i][j]-'1');
			tx[t]=i;ty[t]=j;n=max(n,t+1);
		}
	}
	m=n;
	rep(i,h) rep(j,w){
		if(ma[i][j]=='B'){tx[m]=i;ty[m]=j;m++;}
	}
	rep(i,n) cin>>tv[i];
	aedge(0,sx,sy,0);
	now=next;next=cl;
	for(int i=0;now.size()>0;i++){
		rep(j,now.size()){
			tint p=now[j];
			int x=p.fi.fi,y=p.fi.se,mask=p.se;
			rep(k,4){
				int nx=x+dx[k],ny=y+dy[k],nm=mask;
				if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
				if(ma[nx][ny]!='.' && ma[nx][ny]!='S') continue;
				//if(nx>bx && y!=ny && min(y,ny)==by) nb=(nb^1);
				rep(l,m){
					if(nx>tx[l] && y!=ny && min(y,ny)==ty[l]) nm=(nm^(1<<l));
				}
				aedge(i+1,nx,ny,nm);
			}
		}
		now=next;next=cl;
	}
	int out=0;
	rep(i,(1<<n)){
		int t=-dp[sx][sy][i];
		rep(j,n){
			if((i&(1<<j))) t+=tv[j];
		}
		out=max(out,t);
	}
	cout<<out<<endl;
}