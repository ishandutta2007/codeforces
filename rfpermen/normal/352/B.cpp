#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,x,sz;
vector<int> v[MAX];
vector<pii> ans;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x;
    	v[x].pb(i);
	}
	rep(i,1,100000){
		if(v[i].empty())continue;
		sz = v[i].size()-1;
		if(!sz){ans.pb({i,0}); continue;}
		if(sz==1){ans.pb({i,v[i][1]-v[i][0]}); continue;}
		sz-=2;
		rep(j,0,sz){
			if(v[i][j+2]-v[i][j+1]!=v[i][j+1]-v[i][j])break;
			if(j==sz)ans.pb({i,v[i][1]-v[i][0]});
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.fi<<" "<<i.se<<endl;
    return 0;
}