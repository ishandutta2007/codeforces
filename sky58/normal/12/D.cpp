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
typedef pair<int,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 524288
int dat[N*2+10],a[N],b[N],c[N];
int inf=1100000000;
vector <tint> p;
vector <int> v;
map<int,int> de;
int query(int a,int b,int k,int l,int r){
	if(r<=a || b<=l) return 0;
	if(a<=l && r<=b) return dat[k];
	int vl=query(a,b,k*2+1,l,(l+r)/2);
	int vr=query(a,b,k*2+2,(l+r)/2,r);
	return max(vl,vr);
}
void update(int k,int a){
	k+=N-1;
	dat[k]=max(a,dat[k]);
	while(k>0){
		k=(k-1)/2;
		dat[k]=max(dat[k*2+1],dat[k*2+2]);
	}
	return;
}
int main()
{
	int i,n,out=0,it=0;
	memset(dat,0,sizeof(dat));
	cin>>n;
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);
	rep(i,n) scanf("%d",&c[i]);
	rep(i,n){
		//cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
		p.pb(mp(a[i],mp(b[i],c[i])));
		v.pb(b[i]);
	}
	sort(All(p));reverse(All(p));p.pb(mp(-1,mp(0,0)));
	sort(All(v));v.erase((All(v)),v.end());
	rep(i,v.size()) de[v[i]]=i;
	//rep(i,n) cout<<p[i].fi<<' '<<p[i].se.fi<<' '<<p[i].se.se<<endl;
	while(it<n){
		int nex=it;
		while(p[nex].fi==p[it].fi) nex++;
		//cout<<it<<'a'<<nex<<endl;
		REP(i,it,nex){
			//cout<<de[p[i].se.fi]<<' '<<p[i].se.se<<endl;
			//cout<<query(de[p[i].se.fi]+1,n+1,0,0,N)<<endl;
			if(query(de[p[i].se.fi]+1,n+1,0,0,N)>p[i].se.se) out++;
		}
		REP(i,it,nex){
			//cout<<de[p[i].se.fi]<<'b'<<p[i].se.se<<endl;
			update(de[p[i].se.fi],p[i].se.se);
		}
		it=nex;
	}
	cout<<out<<endl;
	return 0;
}