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
priority_queue<pint> qu;
map<int,int> me;
vector <vector <int> > out;
int main()
{
	int i,j,n,a;
	cin>>n;
	rep(i,n){
		scanf("%d",&a);me[a]++;
	}
	int m=me.size();
	map<int,int>::iterator it = me.begin();
	while(it!=me.end()){
		qu.push(mp((*it).se,(*it).fi));it++;
	}
//	cout<<m<<endl;
/*	cout<<m/3<<endl;
	rep(i,m/3){
		vector <int> out;
		rep(j,3){
			out.pb((*it).fi);it++;
		}
		reverse(All(out));
		rep(j,3){
			cout<<out[j];if(j<2) cout<<" ";else cout<<endl;
		}
	}
*/
	while(qu.size()>2){
		vector <int> b;vector <pint> c;
		rep(i,3){
			pint p=qu.top();qu.pop();b.pb(p.se);
			if(p.fi>1) c.pb(mp(p.fi-1,p.se));
		}
		sort(rAll(b));out.pb(b);
		rep(i,c.size()) qu.push(c[i]);
	}
	cout<<out.size()<<endl;
	rep(i,out.size()){
		rep(j,3){
			cout<<out[i][j];if(j<2) cout<<" ";else cout<<endl;
		}
	}
	return 0;
}