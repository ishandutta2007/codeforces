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
int main()
{
	double now=0.0,a,d,v,t;int i,n,ti,vi;
	cin>>n>>a>>d;//cout<<a<<' '<<d<<endl;
	rep(i,n){
		scanf("%d",&ti);scanf("%d",&vi);
		t=0.0+ti;v=0.0+vi;//cout<<t<<' '<<v<<endl;
		if(d>v*v*0.5/a) now=max(now,d/v+v*0.5/a+t);
		else now=max(now,sqrt(2.0*d/a)+t);
		printf("%.12f\n",now);
	}
	return 0;
}