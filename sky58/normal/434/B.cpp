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
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[4][1010][1010];
int ma[1010][1010],m2[1010][1010];
int n,m;
int rox(int x,int y){
	return n-1-y;
}
int roy(int x,int y){
	return x;
}
int cal(int x,int y,int k){
	rep(i,k){
		int nx=rox(x,y),ny=roy(x,y);
		x=nx;y=ny;
	}
	return ma[x][y];
}
int main()
{
	int o,q,x,y;
	cin>>n>>m>>q;
	rep(i,n) rep(j,m) cin>>ma[i][j];
	n=max(n,m);m=max(n,m);
	rep(k,4){
		rep(i,n){
			rep(j,m){
				if(cal(i,j,k)<1) dp[k][i][j]=0;
				else{
					if(j>0) dp[k][i][j]=dp[k][i][j-1]+1;else dp[k][i][j]=1;
				}
			}
		}
	}
	rep(l,q){
		cin>>o>>x>>y;
		x--;y--;
		if(o==1){
			ma[x][y]=1-ma[x][y];
			rep(k,4){
				rep(j,m){
					if(cal(x,j,k)<1) dp[k][x][j]=0;
					else{
						if(j>0) dp[k][x][j]=dp[k][x][j-1]+1;else dp[k][x][j]=1;
					}
				}
				rep(i,3){
					int nx=rox(x,y),ny=roy(x,y);
					x=nx;y=ny;
				}
			}
		}
		if(o==2){
			int ret=0;
			rep(k,4){
				/*if(l==4){
					cout<<x<<' '<<y<<endl;
					rep(i,n){
						rep(j,m) cout<<dp[k][i][j];cout<<endl;
					}
				}*/
				int le=x,ri=x,maxh=dp[k][x][y];
				for(int i=maxh;i>0;i--){
					while(le>0 && dp[k][le-1][y]>=i) le--;
					while(ri<n-1 && dp[k][ri+1][y]>=i) ri++;
					ret=max(ret,(ri-le+1)*i);
				}
				rep(i,3){
					int nx=rox(x,y),ny=roy(x,y);
					x=nx;y=ny;
				}
			}
			cout<<ret<<endl;
		}
	}
}