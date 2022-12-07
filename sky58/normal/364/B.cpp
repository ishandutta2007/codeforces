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
bool dp[520000];
int a[55];
vector<int> v;
int main()
{
	int n,d;
	cin>>n>>d;rep(i,n) cin>>a[i];
	memset(dp,false,sizeof(dp));dp[0]=true;
	rep(i,n) for(int j=500010;j>=0;j--){
		if(dp[j]) dp[j+a[i]]=true;
	}
	rep(i,500010){
		if(dp[i]) v.pb(i);
	}
	v.pb(520000);
	int now=0,t=0;
	while(1){
		int nex=upper_bound(All(v),v[now]+d)-v.begin()-1;
		if(now==nex) break;now=nex;t++;
	}
	cout<<v[now]<<' '<<t<<endl;
}