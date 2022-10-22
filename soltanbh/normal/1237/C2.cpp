#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=50000+9;

int n,x,y,z,cor[N][3],mark1[N],mark2[N];
vector<pair<int,int> > ans,p,s,g;
map<pair<int,int>,int> mp1;
map<int,int> mp2;

void solve3(){
	sort(g.begin(),g.end());
	for(int i=0;i<g.size();i+=2)
		ans.pb(mp(g[i].S,g[i+1].S));	
}
void solve2(){
	sort(s.begin(),s.end());
	f(i,0,s.size()){
		if(mp2[cor[s[i].S][2]]>0){
			ans.pb(mp(s[i].S,mp2[cor[s[i].S][2]]));
			mark2[s[i].S]=mark2[mp2[cor[s[i].S][2]]]=1;
			mp2[cor[s[i].S][2]]=0;
		}
		else
			mp2[cor[s[i].S][2]]=s[i].S;
	}
	f(i,0,s.size())
		if(mark2[s[i].S]==0)
			g.pb(mp(cor[s[i].S][2],s[i].S));
	solve3();
}
void solve1(){
	sort(p.begin(),p.end());
	f(i,0,p.size()){
		if(mp1[mp(cor[p[i].S][1],cor[p[i].S][2])]>0){
			ans.pb(mp(p[i].S,mp1[mp(cor[p[i].S][1],cor[p[i].S][2])]));
			mark1[p[i].S]=1,mark1[mp1[mp(cor[p[i].S][1],cor[p[i].S][2])]]=1;
			mp1[mp(cor[p[i].S][1],cor[p[i].S][2])]=0;
		}
		else
			mp1[mp(cor[p[i].S][1],cor[p[i].S][2])]=p[i].S;
	}
	f(i,0,p.size())
		if(mark1[p[i].S]==0)
			s.pb(mp(cor[p[i].S][1],p[i].S));
	solve2();
}
int main(){
	cin>>n;
	f(i,1,n+1){
		scanf("%d%d%d",&cor[i][0],&cor[i][1],&cor[i][2]);
		p.pb(mp(cor[i][0],i));
	}
	solve1();
	f(i,0,ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}