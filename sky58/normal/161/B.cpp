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
vector <vector <int> > out;
vector <int> cl;
int main()
{
	int i,j,s,n,k,mi=1100000000,a,b;double ret=0.0;
	vector <pint> pe,st;
	cin>>n>>k;
	rep(i,k+10) out.pb(cl);
	rep(i,n){
		cin>>a>>b;
		if(b==1) st.pb(mp(a,i));
		else pe.pb(mp(a,i));
		ret+=a;//mi=min(mi,a);
	}
	s=st.size();sort(All(st));reverse(All(st));
	if(s<k){
		rep(i,s){out[i].pb(st[i].se);ret-=0.5*st[i].fi;}
		rep(i,pe.size()){
			out[i%(k-s)+s].pb(pe[i].se);
		}
	}
	else{
		rep(i,k-1){out[i].pb(st[i].se);ret-=0.5*st[i].fi;}
		REP(i,k-1,s){out[k-1].pb(st[i].se);mi=min(mi,st[i].fi);}
		rep(i,pe.size()){
			out[k-1].pb(pe[i].se);mi=min(mi,pe[i].fi);
		}
		ret-=0.5*mi;
	}
//	cout<<moji(ret/2)<<".";
//	if(ret%2>0) cout<<"5"<<endl;else cout<<"0"<<endl;
	printf("%.1f\n",ret);
	rep(i,k){
		cout<<out[i].size();
		rep(j,out[i].size()) cout<<' '<<out[i][j]+1;
		cout<<endl;
	}
	return 0;
}