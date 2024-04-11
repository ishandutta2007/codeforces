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
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,x,y;
vector<pii> a,b,c,d;
vector<pair<int,pair<int,char>> > ans;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>x>>y;
    	if(y>=0){
    		if(x>=0)a.pb({y,x});
    		else b.pb({y,-x});
		}
		else {
			if(x>=0)c.pb({-y,x});
    		else d.pb({-y,-x});
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	sort(d.begin(),d.end());
	for(auto i:a){
		if(i.fi==0){
			ans.pb({1,{i.se,'R'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.se,'L'}});
			ans.pb({3,{-1,'a'}});
		}
		else if(i.se==0){
			ans.pb({1,{i.fi,'U'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.fi,'D'}});
			ans.pb({3,{-1,'a'}});
		}
		else {
			ans.pb({1,{i.fi,'U'}});
			ans.pb({1,{i.se,'R'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.se,'L'}});
			ans.pb({1,{i.fi,'D'}});
			ans.pb({3,{-1,'a'}});
		}
	}
	for(auto i:b){
		if(i.fi==0){
			ans.pb({1,{i.se,'L'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.se,'R'}});
			ans.pb({3,{-1,'a'}});
		}
		else {
			ans.pb({1,{i.fi,'U'}});
			ans.pb({1,{i.se,'L'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.se,'R'}});
			ans.pb({1,{i.fi,'D'}});
			ans.pb({3,{-1,'a'}});
		}
	}
	for(auto i:c){
		if(i.se==0){
			ans.pb({1,{i.fi,'D'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.fi,'U'}});
			ans.pb({3,{-1,'a'}});
		}
		else {
			ans.pb({1,{i.fi,'D'}});
			ans.pb({1,{i.se,'R'}});
			ans.pb({2,{-1,'a'}});
			ans.pb({1,{i.se,'L'}});
			ans.pb({1,{i.fi,'U'}});
			ans.pb({3,{-1,'a'}});
		}
	}
	for(auto i:d){
		ans.pb({1,{i.fi,'D'}});
		ans.pb({1,{i.se,'L'}});
		ans.pb({2,{-1,'a'}});
		ans.pb({1,{i.se,'R'}});
		ans.pb({1,{i.fi,'U'}});
		ans.pb({3,{-1,'a'}});
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		if(i.fi!=1)cout<<i.fi<<endl;
		else cout<<i.fi<<" "<<i.se.fi<<" "<<i.se.se<<endl;
	}
    return 0;
}