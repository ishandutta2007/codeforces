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
double pi=3.14159265358979;
int main()
{
	int n,R,r;
	cin>>n>>R>>r;
	if(n==1){
		if(R>=r) cout<<"YES"<<endl;else cout<<"NO"<<endl;return 0;
	}
	if(n==2){
		if(R>=r*2) cout<<"YES"<<endl;else cout<<"NO"<<endl;return 0;
	}
	if(n==6){
		if(R>=r*3) cout<<"YES"<<endl;else cout<<"NO"<<endl;return 0;
	}
	if(sin(pi/n)*(1.0*R-r)>1.0*r) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}