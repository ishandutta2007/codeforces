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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <int> so;
vector <int> gr[110000],ne[110000];
int a[110000],dp[110000];
bool sos[110000];
int main()
{
	int i,j,n,out=0;
	memset(sos,false,sizeof(sos));
	for(i=2;i<110000;i++){
		if(!sos[i]) so.pb(i);
		for(j=i*2;j<110000;j+=i) sos[j]=true;
	}
	cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
		int t=a[i];
		for(j=0;so[j]*so[j]<=t;j++){
			if(a[i]%so[j]!=0) continue;
			gr[so[j]].pb(i);
			while(t%so[j]==0) t/=so[j];
		}
		if(t>1) gr[t].pb(i);
	}
	rep(i,105000){
		if(gr[i].size()<2) continue;
		rep(j,gr[i].size()-1){
			//cout<<gr[i][j]<<' '<<gr[i][j+1]<<endl;
			ne[gr[i][j]].pb(gr[i][j+1]);
		}
	}
	memset(dp,0,sizeof(dp));
	rep(i,n){
		dp[i]++;if(out<dp[i]) out=dp[i];
		rep(j,ne[i].size()) dp[ne[i][j]]=max(dp[ne[i][j]],dp[i]);
	}
	cout<<out<<endl;
	return 0;
}