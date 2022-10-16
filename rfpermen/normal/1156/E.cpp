#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define mosex push_back
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
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,p[MAX],sz[MAX],x[MAX],a,b,k;
pii y[MAX];
ll ans;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], y[i] = {x[i],i}, p[i] = i, sz[i] = 1;
    x[0] = x[n+1] = n+1;
    sort(y+1,y+1+n);
    rep(i,1,n){
    	k = y[i].se;
    	if(x[k-1]<i&&x[k+1]<i){
    		a = par(k-1), b = par(k+1);
    		if(sz[a]<sz[b]){
    			rap(j,k-1,1){
    				if(x[j]>i)break;
    				if(par(y[i-x[j]].se)==b)ans++;
				}
			}
			else {
				rep(j,k+1,n){
    				if(x[j]>i)break;
    				if(par(y[i-x[j]].se)==a)ans++;
				}
			}
		}
		if(x[k-1]<i)p[k] = par(k-1);
		if(x[k+1]<i){
			a = par(k), b = par(k+1);
			if(sz[a]<sz[b])sz[b]+= sz[a], sz[a] = 0, p[a] = b;
			else sz[a]+= sz[b], sz[b] = 0, p[b] = a;
		}
	}
	cout<<ans<<endl;
	return 0;
}