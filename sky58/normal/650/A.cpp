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
map<int,lint> xs,ys;
map<pint,lint> es;
int main()
{
	int n,x,y;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d %d",&x,&y);
		xs[x]++;ys[y]++;es[mp(x,y)]++;
	}
	lint out=0;
	map<int,lint>::iterator it=xs.begin();
	while(it!=xs.end()){
		lint t=(*it).se;
		out+=t*(t-1)/2;
		it++;
	}
	it=ys.begin();
	while(it!=ys.end()){
		lint t=(*it).se;
		out+=t*(t-1)/2;
		it++;
	}
	map<pint,lint>::iterator i2=es.begin();
	while(i2!=es.end()){
		lint t=(*i2).se;
		out-=t*(t-1)/2;
		i2++;
	}
	cout<<out<<endl;
}