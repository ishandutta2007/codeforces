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
int cal(int a,int b){
	if(a>0) return a/b;return a/b-1;
}
int main()
{
	int a,b,x1,x2,y1,y2,x,y;
	cin>>a>>b>>x1>>y1>>x2>>y2;
	x=abs(cal(x1+y1,2*a)-cal(x2+y2,2*a)),y=abs(cal(x1-y1,2*b)-cal(x2-y2,2*b));
//	cout<<abs(cal(x1+y1,2*a)-cal(x2+y2,2*a))+abs(cal(x1-y1,2*b)-cal(x2-y2,2*b))<<endl;
	cout<<max(x,y)<<endl;
	return 0;
}