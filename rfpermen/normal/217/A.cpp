#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,a,b,p[105],sz,ans;
vector<int> x[1005],y[1005];
bool v[105];
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>a>>b;
    	p[i] = i;
    	x[a].pb(i);
    	y[b].pb(i);
	}
	rep(i,1,1000){
		if(x[i].size()>1){
			sz = x[i].size()-1;
			rep(j,1,sz){
				a = par(x[i][j-1]), b = par(x[i][j]);
				if(a==b)continue;
				p[a] = b;
			}
		}
		if(y[i].size()>1){
			sz = y[i].size()-1;
			rep(j,1,sz){
				a = par(y[i][j-1]), b = par(y[i][j]);
				//cout<<a<<" "<<b<<endl;
				if(a==b)continue;
				p[a] = b;
				//cout<<p[a]<<" "<<p[b]<endl;
			}
		}
	}
	//cout<<"p[2] "<<p[1]<<endl;
	//cout<<y[1].size()<<endl;cout<<par(i)<<endl, 
	rep(i,1,n)v[par(i)]=1;
	rep(i,1,n)ans+=v[i];
	cout<<ans-1<<endl;
    return 0;
}