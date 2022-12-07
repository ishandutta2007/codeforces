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
#define N 252521
int pos[N],id[N],x[N];
int n;
int cal(int a,int b){
	vector<int> v;v.pb(a);
	rep(i,114514){
		//cout<<a<<endl;
		if(i>1 && a==v[i-2]){
			if(v[i-1]==v[i-2]) return id[v[i-1]];
			b%=(2*abs(pos[v[i-1]]-pos[v[i-2]]));
		}
		if(i%2<1){
			int ne=lower_bound(pos,pos+n+1,pos[a]+b+1)-pos-1;
			b-=pos[ne]-pos[a];a=ne;
		}
		else{
			int ne=lower_bound(pos,pos+n+1,pos[a]-b)-pos;
			if(a==ne) return id[a];
			b-=pos[a]-pos[ne];a=ne;
		}
		v.pb(a);
	}
}
int main()
{
	int m,a,b;
	vector<pint> v;
	scanf("%d %d",&n,&m);
	rep(i,n){
		scanf("%d",&a);
		v.pb(mp(a,i));
		x[i]=a;
	}
	sort(All(v));
	rep(i,n) pos[i]=v[i].fi,id[i]=v[i].se;pos[n]=2002002002;
	rep(i,m){
		scanf("%d %d",&a,&b);
		a=lower_bound(pos,pos+n+1,x[a-1])-pos;
		//cout<<a<<' '<<b<<endl;
		printf("%d\n",cal(a,b)+1);
	}
}