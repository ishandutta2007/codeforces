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
typedef pair<double,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int find(int x){
		return -data[x];
	}
};
int a[114514];
vector<tint> v;
int main()
{
	int n,m,x,y;
	double out=0.0;
	cin>>n>>m;
	rep(i,n) cin>>a[i];
	rep(i,m){
		cin>>x>>y;x--;y--;
		v.pb(mp(min(a[x],a[y]),mp(x,y)));
	}
	sort(All(v));reverse(All(v));
	unionf uni(n+10);
	rep(i,m){
		x=v[i].se.fi;y=v[i].se.se;
		if(uni.finds(x,y)) continue;
		out+=v[i].fi*uni.find(uni.root(x))*uni.find(uni.root(y));
		uni.unions(x,y);
	}
	printf("%.12f\n",out*2/n/(n-1));
}