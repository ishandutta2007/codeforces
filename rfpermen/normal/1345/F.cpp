#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
inline pair<ll,bool> f(ll k,ll tgt){
	ll le = 1,ri = k,mid,df,ret = 0;
	while(le<=ri){
		mid = le+ri>>1;
		df = k - 3*mid*(mid-1) - 1;
		if(df>=tgt)ret = mid, le = mid+1;
		else ri = mid-1;
	}
	df = k - 3*ret*(ret-1) - 1;
	return {ret,df==tgt&&ret!=0};
}
 
ll n,k,x[MAX],y[MAX],hit,cnt;
bool tmp[MAX];
pair<ll,bool> res;
 
int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll le,ri,mid;
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    
    le = -3*INF, ri = 1e9;
    while(le<=ri){
    	mid = le+ri>>1;
    	cnt = hit = 0;
    	rep(i,1,n){
    		res = f(x[i],mid);
    		cnt+= res.fi, hit+= res.se;
    		y[i] = res.fi, tmp[i] = res.se;
		}
		if(k<=cnt&&k>=cnt-hit){
			hit = cnt-k;
			rep(i,1,n){
				if(tmp[i]&&hit)--hit, y[i]--;
				cout<<y[i]<<' ';
			}
			cout<<endl;
			return 0;
		}
		if(cnt<k)ri = mid-1;
		else le = mid+1;
	}
	return 1;
	return 0;
}