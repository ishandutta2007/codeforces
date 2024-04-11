#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,r,a,b,x,y;
pii pos[MAX],neg[MAX];

inline bool cmp(pii aa,pii bb){
	return aa.fi+aa.se>bb.fi+bb.se;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>r;
    rep(i,1,n){
    	cin>>a>>b;
    	if(b<0)neg[++y] = {max(a,-b),b};
    	else pos[++x] = {a,b};
	}
	sort(pos+1,pos+1+x);
	rep(i,1,x){
		if(r<pos[i].fi)return cout<<"NO\n",0;
		r+=pos[i].se;
	}
	sort(neg+1,neg+1+y,cmp);
	rep(i,1,y){
		if(r<neg[i].fi)return cout<<"NO\n",0;
		r+=neg[i].se;
	}
	cout<<"YES\n";
	return 0;
}