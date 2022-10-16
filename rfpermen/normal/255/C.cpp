#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,x,vis[MAX*MAX],ans,id,ls;
vector<int> v[4*MAX];

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x;
    	if(!vis[x])vis[x] = ++id;
    	x = vis[x];
    	v[x].pb(i);
	}
	++n;
	auto it = v[1].end();
	rep(i,1,id)ans = max(ans,(int)v[i].size());
	rep(i,1,id)rep(j,i+1,id){
		ls = v[j][0];
		rep(k,3,n){
			if(k&1){
				it = lower_bound(all(v[i]),ls);
				if(it==v[i].end()){ans = max(ans,k-1); break;}
			}
			else {
				it = lower_bound(all(v[j]),ls);
				if(it==v[j].end()){ans = max(ans,k-1); break;}
			}
			ls = *it;
		}
	}
	cout<<ans<<endl;
	return 0;
}