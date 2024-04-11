#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,Mx=1e9+2;

int n,t,fg=-1,lg,ans,p1,p2,res;
pair<int,char> a[N];
vector<int> p[3];
vector<int> v;

void case1(){
	if(sz(p[1])) ans+=a[lst(p[1])].F-a[p[1][0]].F;
	if(sz(p[2])) ans+=a[lst(p[2])].F-a[p[2][0]].F;
	cout<<ans;
	exit(0);
}

int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i].F>>a[i].S;
		if(a[i].S=='G'){ p[0].pb(i); }
		else if(a[i].S=='R'){
			p[1].pb(i);
		}
		else{
			p[2].pb(i);
		}
	}
	if(!sz(p[0])) case1();
	f(i,1,3)
		if(p[i].size())
			ans+=max(a[lst(p[i])].F-a[lst(p[0])].F,0)+max(a[p[0][0]].F-a[p[i][0]].F,0);
	if(sz(p[0])==1) return cout<<ans,0;
	p1=p[0][0];
	p2=p[0][0]+1;
	while(p1!=lst(p[0])){
		if(a[p2].S!='G') p2++;
		else{
			int res1=0,res2=0,r=a[p2].F-a[p1].F;
			int last=a[p1].F;
			f(i,p1+1,p2+1)
				if(a[i].S=='G' || a[i].S=='B'){
					maxm(res1,a[i].F-last);
					last=a[i].F;
				}
			last=a[p1].F;
			f(i,p1+1,p2+1)
				if(a[i].S=='G' || a[i].S=='R'){
					maxm(res2,a[i].F-last);
					last=a[i].F;
				}
			ans+=min(2*r,3*r-res1-res2);
			p1=p2;
			p2++;
		}
	}
	cout<<ans;
}