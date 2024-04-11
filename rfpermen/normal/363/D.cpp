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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,m,k,x[MAX],y[MAX],le,ri,mid,ans,hit,id,py,rem;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)cin>>x[i];
    rep(i,1,m)cin>>y[i];
    sort(x+1,x+1+n);
    sort(y+1,y+1+m);
    le = 1, ri = min(n,m);
    while(le<=ri){
    	mid = le+ri>>1;
    	id = n-mid;
    	py = 0, rem = k;
    	rep(i,1,mid){
    		if(x[id+i]>=y[i])py+=y[i];
    		else py+=x[id+i], rem-=y[i]-x[id+i];
		}
		if(rem<0)ri = mid-1;
		else ans = mid, hit = max(0ll,py-rem), le = mid+1;
	}
	cout<<ans<<' '<<hit<<endl;
	return 0;
}