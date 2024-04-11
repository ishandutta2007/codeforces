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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,x[100],y,z,sz,T;
string s,t;
vector<int> ans[3];
bool st;
int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i];
    	if(x[i]>0)st = 1;
	}
    sort(x+1,x+1+n);
    ans[0].pb(x[1]);
    if(!st){
    	ans[1].pb(x[2]);
    	ans[1].pb(x[3]);
    	rep(i,4,n)ans[2].pb(x[i]);
	}
    else rep(i,2,n){
    	if(x[i]>0)ans[1].pb(x[i]);
    	else ans[2].pb(x[i]);
	}
	cout<<ans[0].size()<<" "; for(auto i:ans[0])cout<<i<<" "; cout<<endl;
	cout<<ans[1].size()<<" "; for(auto i:ans[1])cout<<i<<" "; cout<<endl;
	cout<<ans[2].size()<<" "; for(auto i:ans[2])cout<<i<<" "; cout<<endl;
    return 0;
}