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
#define N 720720
int dp[800000],dp2[800000];
vector <int> now,next,cl;
void aedge1(int x,int i){
	if(x<0 || x>=N) return;if(dp[x]<=i) return;
	dp[x]=i;next.pb(x);return;
}
void aedge2(int x,int i){
	if(x<0 || x>=N) return;if(dp2[x]<=i) return;
	dp2[x]=i;next.pb(x);return;
}
int main()
{
	lint a,b,adiv,bdiv;int i,j,k,l,amod,bmod,inf=100000000;
	cin>>b>>a>>l;
	adiv=a/N;bdiv=b/N;amod=(int)(a%N);bmod=(int)(b%N);
	rep(i,N) dp[i]=dp2[i]=inf;
	
	aedge1(bmod,0);now=next;next=cl;
	for(i=0;now.size()>0;i++){
		rep(j,now.size()){
			int x=now[j];//cout<<x<<' '<<dp[x]<<endl;
			REP(k,1,l+1) aedge1((x/k)*k,i+1);
			if(x>0) aedge1(x-1,i+1);
		}
		now=next;next=cl;
	}
	
	aedge2(N-1,1);now=next;next=cl;
	for(i=1;now.size()>0;i++){
		rep(j,now.size()){
			int x=now[j];
			REP(k,1,l+1) aedge2((x/k)*k,i+1);
			if(x>0) aedge2(x-1,i+1);
		}
		now=next;next=cl;
	}
	
	if(adiv==bdiv) cout<<dp[amod]<<endl;
	else cout<<(bdiv-adiv-1)*dp2[0]+dp[0]+dp2[amod]<<endl;
	return 0;
}