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
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,k,a,b,c,x,y,z,sz,cnt,ans,ttl,nw,id;
ll dp[MAX][2];
string s,t;
vector<pii> v;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n){
    	if(i&1)rep(j,1,m)v.pb({i,j});
    	else rap(j,m,1)v.pb({i,j});
	}
	//for(auto i:v)cout<<i.fi<<" "<<i.se<<endl;
	while(k--){
		if(!k){
			cout<<n*m-id<<" ";
			n = n*m-1;
			rep(i,id,n)cout<<v[i].fi<<" "<<v[i].se<<" ";
		}
		else {
			cout<<"2 "<<v[id].fi<<" "<<v[id].se<<" ";id++;
			cout<<v[id].fi<<" "<<v[id].se<<endl;id++;
		}
	}
    return 0;
}