#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+1;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,le,ri,mid,a,b;
ll z[MAX],ans;
pii x[MAX];

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    rep(i,1,n)cin>>x[i].se>>x[i].fi;
    sort(x+1,x+1+n);
    rep(i,1,n)swap(x[i].fi,x[i].se);
    z[0] = 1;
    rep(i,1,n){
    	z[i] = z[i-1];
    	a = b = -1;
    	le = 0, ri = i-1;
    	while(le<=ri){
    		mid = le+ri>>1;
    		if(x[mid].se>=x[i].fi)a = mid, ri = mid-1;
    		else le = mid+1;
		}
    	le = 0, ri = i-1;
    	while(le<=ri){
    		mid = le+ri>>1;
    		if(x[mid].se>=x[i].se)ri = mid-1;
    		else b = mid, le = mid+1;
		}
		if(a>b||a==-1||b==-1)continue;
		if(a!=0)a = z[a-1];
		z[i] = (z[i]+z[b]-a)%MOD;
		if(x[i].se==m)ans = (ans+z[b]-a)%MOD;
	}
	cout<<(ans+MOD)%MOD<<endl;
	return 0;
}