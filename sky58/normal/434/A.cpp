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
lint a[114514],sum[114514];
vector<lint> gr[114514];
int main()
{
	int n,m;lint out=0,su=0;
	cin>>n>>m;
	rep(i,m) cin>>a[i];
	rep(i,m-1){
		if(a[i]==a[i+1]) continue;
		gr[a[i]].pb(a[i+1]);gr[a[i+1]].pb(a[i]);
		sum[a[i]]+=abs(a[i]-a[i+1]);
		sum[a[i+1]]+=abs(a[i]-a[i+1]);
		su+=abs(a[i]-a[i+1]);
	}
	rep(i,n+1){
		int t=gr[i].size();lint s=0;
		if(t<1) continue;
		sort(All(gr[i]));
		rep(j,t) s+=abs(i-gr[i][j]);
		rep(j,t) s-=abs(gr[i][j]-gr[i][t/2]);
		out=max(out,s);
	}
	cout<<su-out<<endl;
}