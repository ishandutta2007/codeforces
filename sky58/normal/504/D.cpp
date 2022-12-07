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
int n;
bitset<2015> mat[2015],num[2015];
int zyo[2015][2015];
vector<int> zy[2015];
priority_queue<pint> p,q;
bitset<2015> ng(0);
int print(bitset<2015> in){
	vector<int> t;
	rep(i,2010){
		if(in[i]) t.pb(i);
	}
	cout<<t.size();
	rep(i,t.size()) cout<<' '<<t[i];cout<<endl;
	return t.size();
}
bitset<2015> cal(bitset<2015> in){
	//cout<<p.size()<<endl;
	q=p;
	bitset<2015> ret(0);
	while(q.size()){
		pint r=q.top();q.pop();
		if(in[r.fi]){
			ret^=num[r.se];in^=mat[r.se];
		}
	}
	rep(i,2010){
		if(in[i]) return ng;
	}
	return ret;
}
void ins(int it,bitset<2015> in){
	q=p;
	num[it].set(it);
	while(q.size()){
		pint r=q.top();q.pop();
		if(in[r.fi]){
			num[it]^=num[r.se];in^=mat[r.se];
		}
	}
	for(int i=2010;i>=0;i--){
		if(in[i]){p.push(mp(i,it));break;}
	}
	mat[it]=in;
}
bitset<2015> dec(string s){
	vector<int> ka(2015,0);
	bitset<2015> ret(0);
	reverse(All(s));
	rep(i,s.size()){
		int t=(s[i]-'0');
		rep(j,zy[i].size()){
			if((t&1)) ka[zy[i][j]]++;
			if((t&2)) ka[zy[i][j]+1]++;
			if((t&4)) ka[zy[i][j]+2]++;
			if((t&8)) ka[zy[i][j]+3]++;
		}
	}
	rep(i,2010){
		ka[i+1]+=ka[i]/2;ka[i]%=2;if(ka[i]>0) ret.set(i);
	}
	return ret;
}
int main()
{
	string s;
	//int s;
	memset(zyo,0,sizeof(zyo));zyo[0][0]=1;
	rep(i,2013){
		rep(j,2005){
			if(zyo[i][j]>0) zy[i].pb(j);
			zyo[i+1][j+1]+=zyo[i][j],zyo[i+1][j+3]+=zyo[i][j];
		}
		rep(j,2010){
			zyo[i+1][j+1]+=zyo[i+1][j]/2;zyo[i+1][j]%=2;
		}
	}
	cin>>n;
	rep(i,n){
		cin>>s;
		bitset<2015> now=dec(s);
		//bitset<2015> now(s);
		bitset<2015> ret=cal(now);
		if(print(ret)<1) ins(i,now);
		else ins(i,now);
	}
}