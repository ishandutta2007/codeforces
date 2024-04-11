#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll x,y,l,r,ans,sz;
set<pll> s;
vector<ll> v;

void dfs(ll a,ll b){
	if(s.count({a,b}))return;
	s.insert({a,b});
	v.pb(a+b);
	double c=a,d=b;
	if(c*x+d<=1e18){
		dfs(a*x,b);
	}
	if(c+d*y<=1e18){
		dfs(a,b*y);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>l>>r;
    dfs(1,1);
    v.pb(l-1),v.pb(r+1);
    sort(v.begin(),v.end());
    sz = v.size()-1;
    rep(i,1,sz){
    	if(l>v[i-1]+1||r<v[i]-1)continue;
    	ans = max(ans,v[i]-v[i-1]-1);
	}
    cout<<ans<<endl;
    return 0;
}