#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,x,id,y[MAX],mx = -1e9;
bool v[MAX];
string s,ans[MAX];
map<string,int> m;
pii z[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>s>>x;
    	if(m[s]==0)m[s] = ++id, ans[id] = s;
    	z[i] = {m[s],x};
    	y[z[i].fi]+=x;
	}
	rep(i,1,id)mx = max(mx,y[i]);
	rep(i,1,id)if(y[i]==mx)v[i] = 1;
	memset(y,0,sizeof y);
    rep(i,1,n){
    	x = z[i].fi;
    	y[x]+=z[i].se;
    	if(y[x]>=mx&&v[x])return cout<<ans[x],0;
	}
    return 0;
}