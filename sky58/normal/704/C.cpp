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
typedef pair<int,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<tint> gr[114514];
lint mo=1000000007;
bool sumi[114514];
vector<int> si[114514];
int n,co=0;
vector<lint> cal(int id){
	vector<lint> dp(4,0),ret(2,0),nx(4,0);
	if(si[id].size()==0) dp[0]=dp[2]=1;
	else if(si[id][0]==1) dp[0]=dp[3]=1;
	else if(si[id][0]==-1) dp[1]=dp[2]=1;
	sumi[id]=true;
	while(1){
		co++;
		int ne=-1;
		rep(i,gr[id].size()){
			if(!sumi[gr[id][i].fi]) ne=i;
		}
		if(ne<0) break;
		int a=gr[id][ne].se.fi/2,b=gr[id][ne].se.fi%2;
		//cout<<a<<' '<<b<<endl;
		rep(i,4) nx[i]=0;
		rep(i,2) rep(j,2) rep(k,2){
			//nx[k*2+(j^((i+b)&(k+a)&1))]+=dp[i*2+j];
			nx[(((i+b)|(k+a))+j)%2+k*2]+=dp[i*2+j];
			//cout<<i<<' '<<j<<' '<<k<<' '<<a<<' '<<b<<' '<<(j^((i+b)&(k+a)&1))<<endl;
		}
		rep(i,4) dp[i]=nx[i]%mo;
		id=gr[id][ne].fi;sumi[id]=true;
	}
	if(si[id].size()==0) ret[0]=(dp[0]+dp[2])%mo,ret[1]=(dp[1]+dp[3])%mo;
	else if(si[id][0]==1) ret[0]=(dp[0]+dp[3])%mo,ret[1]=(dp[1]+dp[2])%mo;
	else if(si[id][0]==-1) ret[0]=(dp[1]+dp[2])%mo,ret[1]=(dp[0]+dp[3])%mo;
	//cout<<ret[0]<<' '<<ret[1]<<endl;
	return ret;
}
vector<lint> cal2(int id){
	vector<lint> dp(8,0),ret(2,0);
	dp[0]=dp[6]=1;
	sumi[id]=true;
	int pre=-1;
	while(1){
		//rep(i,8) cout<<dp[i]<<' ';cout<<id<<endl;
		int ne=-1;
		rep(i,gr[id].size()){
			if(gr[id][i].se.se!=pre) ne=i;
		}
		//cout<<gr[id][ne].se.se<<endl;
		int a=gr[id][ne].se.fi/2,b=gr[id][ne].se.fi%2;
		vector<lint> nx(8,0);
		rep(l,2) rep(i,2) rep(j,2) rep(k,2){
			nx[(((i+b)|(k+a))+j)%2+k*2+l*4]+=dp[l*4+i*2+j];
		}
		rep(i,8) dp[i]=nx[i]%mo;
		pre=gr[id][ne].se.se;
		id=gr[id][ne].fi;
		if(sumi[id]) break;
		sumi[id]=true;
	}
	//rep(i,8) cout<<dp[i]<<' ';cout<<id<<endl;
	ret[0]=(dp[0]+dp[6])%mo;ret[1]=(dp[1]+dp[7])%mo;
	return ret;
}
int main()
{
	memset(sumi,false,sizeof(sumi));
	int m,ed=0,t,x,y;lint out0=1,out1=0;
	scanf("%d %d",&m,&n);
	rep(i,m){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&x);
			int a=1;if(x<0) a=-1;
			x=abs(x);x--;si[x].pb(a);
		}
		else{
			scanf("%d %d",&x,&y);
			int a=0,b=0;if(x<0) a=1;if(y<0) b=1;
			x=abs(x);x--;y=abs(y);y--;
			if(x==y){
				//if(n==12655) cout<<i<<'a'<<endl;
				if(a==b){
					lint o=out0+out1;o%=mo;out0=out1=o;
				}
				else{
					lint o=out0*=2;
					out0=out1*2;out0%=mo;
					out1=o%mo;
				}
				sumi[x]=true;
				continue;
			}
			//cout<<x<<' '<<y<<endl;
			gr[x].pb(mp(y,mp(a+b*2,ed)));gr[y].pb(mp(x,mp(b+a*2,ed)));
			ed++;
		}
	}
	/*if(n==12655){
		rep(i,n){
			if(sumi[i]) cout<<'a'<<i<<endl;
			else if(gr[i].size()==1) cout<<'b'<<i<<endl;
			if(si[i].size()>0) cout<<'c'<<i<<endl;
		}
	}*/
	//cout<<out0<<' '<<out1<<endl;
	rep(i,n){
		if(sumi[i] || gr[i].size()>0 || si[i].size()==0) continue;
		//if(n==12655) cout<<i<<'a'<<endl;
		sumi[i]=true;
		if(si[i].size()==1){
			out0=(out0+out1)%mo;out1=out0;continue;
		}
		if(si[i][0]!=si[i][1]){
			swap(out0,out1);out0*=2;out1*=2;out0%=mo;out1%=mo;
		}
		else{
			out0*=2;out1*=2;out0%=mo;out1%=mo;
		}
	}
	//rep(i,n) cout<<gr[i].size()<<endl;
	rep(i,n){
		if(sumi[i]) continue;
		if(gr[i].size()==1){
		//if(n==12655) cout<<i<<'b'<<endl;
			vector<lint> now=cal(i);
			lint o=out0*now[0]+out1*now[1];
			out1=out1*now[0]+out0*now[1];
			out0=o%mo;out1%=mo;
			//if(n==12655) cout<<co<<endl;
		}
	}
	//cout<<out0<<' '<<out1<<endl;
	rep(i,n){
		if(sumi[i]) continue;
		if(gr[i].size()==2){
		//if(n==12655) cout<<i<<'c'<<endl;
			vector<lint> now=cal2(i);
			lint o=out0*now[0]+out1*now[1];
			out1=out1*now[0]+out0*now[1];
			out0=o%mo;out1%=mo;
		}
	}
	//if(n==12655) swap(out0,out1);
	int ze=0;
	rep(i,n){
		if(!sumi[i]){
			//if(n==12655) cout<<i<<'d'<<endl;
			out1*=2;out1%=mo;ze++;
		}
	}
	cout<<out1%mo<<endl;
}