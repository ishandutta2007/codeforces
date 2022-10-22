#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

string s1;
ll x,ans,mod=1e9+7,r,t;

void update(int p,int td){
	string s="";
	f(j,0,td-1){
		for(int i=p;i<s1.size() && s1.size()+s.size()<=x;i++)
			s+=s1[i];
	}
	s1+=s;
}
int main(){
	cin>>t;
	while(t--){
		cin>>x>>s1;
		ans=s1.size();
		r=s1.size()-1;
		f(i,1,x+1){
			ans=(i+1ll*r*(s1[i-1]-'0'))%mod;
			update(i,int(s1[i-1]-'0'));
			r=(ans-i-1+mod)%mod;
		}
		cout<<ans<<endl;
	}
}