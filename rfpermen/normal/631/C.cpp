#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,q,a[MAX],ans[MAX],le,ri,x,y,sz;
vector<pii> v;

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>a[i];
    while(q--){
    	cin>>x>>y;
    	while(!v.empty()){
    		if(v.back().fi<=y)v.pob();
    		else break;
		}
		v.pb({y,x});
	}
	v.pb({0,1});
	rep(i,v[0].fi+1,n)ans[i] = a[i];
	sort(a+1,a+1+v[0].fi);
	ri = v[0].fi, le = 1;
	sz = v.size()-2;
	rep(i,0,sz){
		if(v[i].se&1){
			//asc
			while(v[i].fi!=v[i+1].fi)ans[v[i].fi] = a[ri], ri--, v[i].fi--;
		}
		else {
			//desc
			while(v[i].fi!=v[i+1].fi)ans[v[i].fi] = a[le], le++, v[i].fi--;
		}
	}
	rep(i,1,n)cout<<ans[i]<<" ";
    return 0;
}