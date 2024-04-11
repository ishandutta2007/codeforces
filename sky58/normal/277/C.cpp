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
vector <pint> x2,y2,t;
vector <tint> x,y;
int cal(int len,int want){
	sort(All(t));
	t.pb(mp(len,len));
	vector <pint> s;
	int now=0,i;
	rep(i,t.size()){
		if(now<t[i].fi) s.pb(mp(now,t[i].fi));now=max(now,t[i].se);
	}
	rep(i,s.size()){
		if(want<=s[i].se-s[i].fi) return s[i].fi+want;
		want-=s[i].se-s[i].fi;
	}
	return -1;
}
int main()
{
	int i,j,n,m,k,xa,xb,ya,yb,gran=0;
	cin>>n>>m>>k;
	rep(i,k){
		scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
		if(xa==xb){
			if(ya>yb) swap(ya,yb);x.pb(mp(xa,mp(ya,yb)));
		}
		if(ya==yb){
			if(xa>xb) swap(xa,xb);y.pb(mp(ya,mp(xa,xb)));
		}
	}
	sort(All(x));sort(All(y));
	x.pb(mp(1234567890,mp(0,0)));y.pb(mp(1234567890,mp(0,0)));
	
	int sum=0,now=0;
	rep(i,x.size()){
		if(i>0 && x[i].fi>x[i-1].fi){x2.pb(mp(x[i-1].fi,m-sum));sum=now=0;}
		sum+=max(0,x[i].se.se-max(now,x[i].se.fi));now=max(now,x[i].se.se);
	}
	sum=now=0;
	rep(i,y.size()){
		if(i>0 && y[i].fi>y[i-1].fi){y2.pb(mp(y[i-1].fi,n-sum));sum=now=0;}
		sum+=max(0,y[i].se.se-max(now,y[i].se.fi));now=max(now,y[i].se.se);
	}
	
	int xs=x2.size(),ys=y2.size(),xe=-1,ye=-1;
	
	//rep(i,xs) cout<<x2[i].fi<<' '<<x2[i].se<<endl;
	//rep(i,ys) cout<<y2[i].fi<<' '<<y2[i].se<<endl;
	rep(i,xs) gran^=x2[i].se;if((n-1-xs)%2>0) gran^=m;
	rep(i,ys) gran^=y2[i].se;if((m-1-ys)%2>0) gran^=n;
	if(gran<1){cout<<"SECOND"<<endl;return 0;}
	cout<<"FIRST"<<endl;
	
	if(xs<1) xe=1;
	if(xs>0 && n-1-xs>0){
		if(x2[0].fi>1) xe=1;if(x2[xs-1].fi<n-1) xe=n-1;
		rep(i,xs-1){
			if(x2[i].fi+1<x2[i+1].fi) xe=x2[i].fi+1;
		}
	}
	if(ys<1) ye=1;
	if(ys>0 && n-1-ys>0){
		if(y2[0].fi>1) ye=1;if(y2[ys-1].fi<n-1) ye=n-1;
		rep(i,ys-1){
			if(y2[i].fi+1<y2[i+1].fi) ye=y2[i].fi+1;
		}
	}
	
	if(n-1-xs>0 && (m^gran)<m){
		cout<<xe<<" 0 "<<xe<<' '<<(m-(m^gran))<<endl;return 0;
	}
	if(m-1-ys>0 && (n^gran)<n){
		cout<<"0 "<<ye<<' '<<(n-(n^gran))<<' '<<ye<<endl;return 0;
	}
	
	rep(i,xs){
		if((x2[i].se^gran)<x2[i].se){
			rep(j,x.size()){
				if(x[j].fi==x2[i].fi) t.pb(x[j].se);
			}
			cout<<x2[i].fi<<" 0 "<<x2[i].fi<<' '<<cal(m,x2[i].se-(x2[i].se^gran))<<endl;return 0;
		}
	}
	
	rep(i,ys){
		if((y2[i].se^gran)<y2[i].se){
			rep(j,y.size()){
				if(y[j].fi==y2[i].fi) t.pb(y[j].se);
			}
			cout<<"0 "<<y2[i].fi<<' '<<cal(n,y2[i].se-(y2[i].se^gran))<<' '<<y2[i].fi<<endl;return 0;
		}
	}
	
	return 0;
}