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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX=2e5+5;
const ll MAX2 = 11;
const ll MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

ll n,x,y,ans,fn;
pll z[MAX];
multiset<ll> s;


int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    rep(i,1,n)cin>>z[i].fi>>z[i].se;
    sort(z+1,z+1+n);
    s.insert(2e9);
    rep(i,1,n){
    	auto it = s.upper_bound(-z[i].fi);
    	fn = *it;
    	if((z[i].fi+fn)*y>x||fn==2e9)ans = (ans+x+y*(z[i].se-z[i].fi))%MOD, s.insert(-z[i].se);
    	else ans = (ans+y*(z[i].se+fn))%MOD, s.erase(it), s.insert(-z[i].se);
	}
	cout<<ans;
    return 0;
}