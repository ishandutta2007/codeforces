#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,no-stack-protector") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
#pragma GCC optimize("unroll-loops")
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
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int r,c,ttl,x[105][105],mn;
vector<pii> ans;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>r>>c;
    rep(i,1,r)rep(j,1,c)cin>>x[i][j], ttl+=x[i][j];
    if(!ttl)return cout<<0,0;
    if(r<c){
    	rep(i,1,r){
    		mn = x[i][1];
    		rep(j,1,c)mn = min(mn,x[i][j]);
			ttl-=mn*c;
			rep(j,1,c)x[i][j]-=mn;
			while(mn--)ans.pb({0,i});
		}
		rep(j,1,c){
			mn = x[1][j];
			rep(i,1,r)mn = min(mn,x[i][j]);
			ttl-=mn*r;
			rep(i,1,r)x[i][j]-=mn;
			while(mn--)ans.pb({1,j});
		}
	}
	else {
		rep(j,1,c){
			mn = x[1][j];
			rep(i,1,r)mn = min(mn,x[i][j]);
			ttl-=mn*r;
			rep(i,1,r)x[i][j]-=mn;
			while(mn--)ans.pb({1,j});
		}
		rep(i,1,r){
    		mn = x[i][1];
    		rep(j,1,c)mn = min(mn,x[i][j]);
			ttl-=mn*c;
			rep(j,1,c)x[i][j]-=mn;
			while(mn--)ans.pb({0,i});
		}
	}
	if(ttl!=0)return cout<<-1,0;
	cout<<ans.size()<<endl;
	for(auto i:ans){
		if(i.fi)cout<<"col ";
		else cout<<"row ";
		cout<<i.se<<endl;
	}
    return 0;
}