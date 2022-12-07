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
typedef pair<lint,lint> plint;
typedef pair<plint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint a[114514],b[114514];
int mi[114514],x[114514];
vector<pint> ad[114514];
vector<tint> bai;
plint prod(lint x,lint y){
	plint ret;
	ret.fi=(x/1000000)*y;ret.se=(x%1000000)*y;
	ret.fi+=ret.se/1000000;ret.se%=1000000;
	return ret;
}
bool comp(tint x,tint y){
	return prod(x.fi.fi,y.fi.se)>prod(x.fi.se,y.fi.fi);
}
int main()
{
	int k,n,m,y,z;
	memset(b,0,sizeof(b));
	cin>>k>>n>>m;
	rep(i,k) cin>>a[i];
	rep(i,n){
		cin>>x[i]>>y>>z;
		y--;
		if(x[i]==1 && b[y]<z){
			b[y]=z;mi[y]=i;
		}
		if(x[i]==2) ad[y].pb(mp(z,i));
		if(x[i]==3) bai.pb(mp(mp(z,1),i));
	}
	rep(i,k){
		if(b[i]>a[i]) ad[i].pb(mp(b[i]-a[i],mi[i]));
		if(ad[i].size()>0){
			sort(All(ad[i]));reverse(All(ad[i]));
		}
		rep(j,ad[i].size()){
			bai.pb(mp(mp(a[i]+ad[i][j].fi,a[i]),ad[i][j].se));
			a[i]+=ad[i][j].fi;
		}
	}
	if(bai.size()>0) sort(All(bai),comp);
	int out=min(m,(int)bai.size());
	vector<int> ret;
	rep(j,3) rep(i,out){
		int t=bai[i].se;
		if(x[t]==j+1) ret.pb(t);
	}
	cout<<out<<endl;
	rep(i,out){
		cout<<ret[i]+1;
		if(i<out-1) cout<<' ';else cout<<endl;
	}
}