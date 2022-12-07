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
#include<cassert>
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n);
ostream &operator<<(ostream &os, const vector<int> &a) {
	os<<"[";
	int i;
	for(i=0;i<(int)a.size();i++){
		os<<a[i];
		if(i<a.size()-1) os<<",";
	}
	os<<"]";
	return os; 
}
int g[114514],p[114514],t[114514],out[114514];
int H,W;
void cal(vector<int> w){
	int i;
	vector<pint> x,y,mae,ato;
	//cout<<w<<endl;
	for(i=0;i<(int)w.size();i++){
		if(g[w[i]]==1) x.pb(mp(p[w[i]],w[i]));
		else y.pb(mp(p[w[i]],w[i]));
	}
	if(x.size()>0) sort(All(x));
	if(y.size()>0){
		sort(All(y));reverse(All(y));
	}
	if(y.size()>0) for(i=0;i<(int)y.size();i++) mae.pb(y[i]);
	if(x.size()>0){
		for(i=0;i<(int)x.size();i++) mae.pb(x[i]);
		for(i=0;i<(int)x.size();i++) ato.pb(x[i]);
	}
	if(y.size()>0) for(i=0;i<(int)y.size();i++) ato.pb(y[i]);
	//cout<<mae.size()<<'a'<<ato.size()<<endl;
	for(i=0;i<(int)mae.size();i++) out[mae[i].se]=ato[i].se;
}
void outp(int id){
	if(g[id]==1) printf("%d %d\n",p[id],H);
	else printf("%d %d\n",W,p[id]);
}
int main()
{
	int n,it=0,i;
	vector<pint> v;
	scanf("%d %d %d",&n,&W,&H);
	for(i=0;i<n;i++){
	    //cout<<i<<endl;
		scanf("%d %d %d",&g[i],&p[i],&t[i]);
		v.pb(mp(p[i]-t[i],i));
		//cout<<i<<' '<<p[i]-t[i]<<endl;
	}
	sort(All(v));
	//for(i=0;i<n;i++) cout<<v[i].fi<<' '<<v[i].se<<endl;
	while(it<n){
		int it2=it;
		while(it2<n && v[it].fi==v[it2].fi) it2++;
		//cout<<it<<' '<<it2<<endl;
		vector<int> w;
		for(i=it;i<it2;i++){
			//cout<<i<<' '<<v[i].se<<endl;
			w.pb(v[i].se);
			//cout<<v[i].se<<endl;
		}
		//cout<<w<<endl;
		cal(w);
		it=it2;
	}
	//for(i=0;i<n;i++) cout<<out[i]<<endl;
	for(i=0;i<n;i++) outp(out[i]);
}