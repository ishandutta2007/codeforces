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
	int out1=0,out2=0,t=10,i,n,a;
	vector <int> ti;
	cin>>n;
	rep(i,n){
		cin>>a;ti.pb(a);
	}
	sort(All(ti));
	rep(i,n){
		t+=ti[i];if(t>720) break;
		out1++;out2+=max(0,t-360);
	}
	cout<<out1<<' '<<out2<<endl;
	return 0;
}