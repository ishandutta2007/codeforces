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
#define N 131072
int c[110000],v[110000],ne[110000];
lint dp[110000];
lint inf=1000000000000000000LL;

int main()
{
	int i,n,q,j,k;lint a,b;
	cin>>n>>q;
	rep(i,n) scanf("%d",&v[i]);
	rep(i,n) scanf("%d",&c[i]);
	rep(i,q){
		cin>>a>>b;
		rep(j,n+10) dp[j]=-inf;
		lint ans=0,bns=0,ansk=0;
		rep(j,n){
			lint t=dp[c[j]]+v[j]*a;
			if(ansk!=c[j]) t=max(t,ans+v[j]*b);
			else t=max(t,bns+v[j]*b);
			dp[c[j]]=max(dp[c[j]],t);
			if(t>ans){
				if(ansk!=c[j]) bns=ans;
				ans=t;ansk=c[j];
			}
			if(ansk!=c[j]) bns=max(t,bns);
		}
		cout<<ans<<endl;
	}
	return 0;
}