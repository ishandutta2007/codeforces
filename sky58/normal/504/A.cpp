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
int s[114514],d[114514];
queue<int> one;
vector<pint> out;
int main()
{
	int n;
	cin>>n;
	rep(i,n){
		cin>>d[i]>>s[i];
		if(d[i]==1) one.push(i);
	}
	while(one.size()>0){
		int t=one.front(),u=s[t];one.pop();
		if(d[t]==0) continue;
		out.pb(mp(t,u));
		d[t]--;s[t]^=u;
		d[u]--;s[u]^=t;
		if(d[u]==1) one.push(u);
	}
	cout<<out.size()<<endl;
	rep(i,out.size()) cout<<out[i].fi<<' '<<out[i].se<<endl;
}