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
int dp[45][(1<<20)+10];
int inf=1000,n;
string ma[25];
int dec(char a){
	if(a=='a') return 1;if(a=='b') return -1;return 0;
}
int rec(int t,int mask){
	if(t>=2*n-2) return 0;
	if(dp[t][mask]>-inf) return dp[t][mask];
	if(t%2==0){
		int ret=500;
		rep(i,26){
			char c=(i+'a');int ma2=0;
			rep(j,n){
				if(t+1-j<0 || t+1-j>=n) continue;
				if(c!=ma[j][t+1-j]) continue;
				if((mask&(1<<j)) || (j>0 && (mask&(1<<(j-1))))) ma2+=(1<<j);
			}
			if(ma2>0) ret=min(ret,rec(t+1,ma2)+dec(c));
		}
		//cout<<t<<' '<<mask<<' '<<ret<<endl;
		return dp[t][mask]=ret;
	}
	else{
		int ret=-500;
		rep(i,26){
			char c=(i+'a');int ma2=0;
			rep(j,n){
				if(t+1-j<0 || t+1-j>=n) continue;
				if(c!=ma[j][t+1-j]) continue;
				//cout<<c<<' '<<j<<' '<<ma[j][t+1-j]<<endl;
				if((mask&(1<<j)) || (j>0 && (mask&(1<<(j-1))))) ma2+=(1<<j);
			}
			//cout<<t<<' '<<mask<<' '<<c<<' '<<ma2<<endl;
			if(ma2>0) ret=max(ret,rec(t+1,ma2)+dec(c));
		}
		//cout<<t<<' '<<mask<<' '<<ret<<endl;
		return dp[t][mask]=ret;
	}
}
int main()
{
	cin>>n;
	rep(i,n) cin>>ma[i];
	rep(i,2*n) rep(j,(1<<n)+5) dp[i][j]=-inf;
	int t=rec(0,1)+dec(ma[0][0]);
	if(t>0) cout<<"FIRST"<<endl;
	else if(t<0) cout<<"SECOND"<<endl;
	else cout<<"DRAW"<<endl;
}