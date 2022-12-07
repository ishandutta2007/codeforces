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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
map<int,int> me;
int main()
{
	int i,a,n,m;vector <pint> me2;
	cin>>n;
	rep(i,n){
		scanf("%d",&a);me[a]++;
	}
	map<int,int>::iterator it=me.begin();
	while(it!=me.end()){
		me2.pb((*it));it++;
	}
	m=me2.size();
	rep(i,m-1){
		if(me2[i+1].fi-me2[i].fi!=1){cout<<"NO"<<endl;return 0;}
		me2[i+1].se-=me2[i].se;
		if(i<m-2 && me2[i+1].se<1){cout<<"NO"<<endl;return 0;}
	}
	if(me2[m-1].se==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}