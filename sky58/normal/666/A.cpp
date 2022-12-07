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
set<string> out;
map<pint,int> me;
string s;
void dfs(int now,int pre){
	if(me[mp(now,pre)]>0) return;
	me[mp(now,pre)]=1;
	if(now>6 && s.substr(now-2,2)!=s.substr(now,pre-now)){
		out.insert(s.substr(now-2,2));dfs(now-2,now);
	}
	if(now>7 && s.substr(now-3,3)!=s.substr(now,pre-now)){
		out.insert(s.substr(now-3,3));dfs(now-3,now);
	}
}
int main()
{
	cin>>s;int n=s.size();
	if(n>6){out.insert(s.substr(n-2));dfs(n-2,n);}
	if(n>7){out.insert(s.substr(n-3));dfs(n-3,n);}
	cout<<out.size()<<endl;
	set<string>::iterator it=out.begin();
	while(it!=out.end()){
		cout<<(*it)<<endl;
		it++;
	}
}