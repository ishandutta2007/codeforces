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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <pint> cal(int a,int b,int t){
	vector <pint> ret;
	if(a/t==b/t) ret.pb(mp(a%t,b%t));
	else if(a/t+1<b/t) ret.pb(mp(1,t-1));
	else if(a/t+1==b/t){
		ret.pb(mp(a%t,t-1));ret.pb(mp(1,b%t));
	}
	return ret;
}
int main()
{
	int l1,r1,l2,r2,i,j,k,out=0;
	cin>>l1>>r1>>l2>>r2;
	for(i=1;i<=30;i++){
		int t=(1<<i);
		int a=l1,b=r1,c=l2,d=r2;
		if(a%t==0) a++;
		if(b%t==0) b--;
		if(c%t==0) c++;
		if(d%t==0) d--;
		vector <pint> x=cal(a,b,t),y=cal(c,d,t);
		rep(j,x.size()) rep(k,y.size()){
			out=max(out,min(y[k].se,x[j].se)-max(y[k].fi,x[j].fi)+1);
		}
	}
	cout<<out<<endl;
	return 0;
}