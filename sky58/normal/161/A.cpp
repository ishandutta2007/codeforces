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
	int i,i1=0,i2=0,n,m,x,y,t;
	vector <pint> a,b,out;
	cin>>n>>m>>x>>y;
	rep(i,n){scanf("%d",&t);a.pb(mp(t,i));}
	rep(i,m){scanf("%d",&t);b.pb(mp(t,i));}
	sort(All(a));sort(All(b));
	while(i1<n && i2<m){
		while(i1<n && a[i1].fi+y<b[i2].fi) i1++;
		while(i2<m && b[i2].fi<a[i1].fi-x) i2++;
		if(i1>=n || i2>=m) break;
		if(b[i2].fi>=a[i1].fi-x && b[i2].fi<=a[i1].fi+y){
			out.pb(mp(a[i1].se,b[i2].se));i1++;i2++;
		}
//		cout<<i1<<' '<<i2<<endl;
	}
	cout<<out.size()<<endl;
	rep(i,out.size()) printf("%d %d\n",out[i].fi+1,out[i].se+1);
	return 0;
}