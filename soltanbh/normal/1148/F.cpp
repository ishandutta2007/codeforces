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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9,M=62;

ll n,ans,sum,mask[N],val[N],mark[N];
vector<ll> g[N],a[N];

bool is_bit(ll mask,ll x){
	return (mask%bit(x+1ll)>=bit(x));
}
void solve(ll x){
	ll s=0;
	f(i,0,a[x].size())
		s+=val[a[x][i]];
	if(s<0){
		ans+=bit(x);
		f(i,0,g[x].size())
			val[g[x][i]]=val[g[x][i]]*(-1*1ll);
	}
}

int main(){
	cin>>n;
	f(i,0,n){
		bool flag=1;
		Get(val[i],mask[i]);
		sum+=val[i];
		f(j,0,M){
			if(is_bit(mask[i],j)){
				if(flag) a[j].pb(i),flag=0;
				g[j].pb(i);
			}
		}
	}
	if(sum>0)
		f(i,0,n)
			val[i]=val[i]*(1ll*-1);
	f_(i,M-1,0)
		solve(i);
	cout<<ans;
}