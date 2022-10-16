#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,y[MAX],x[MAX],tree[1<<20],cnt,a,b,val,res;
ll dp[MAX],ans;
char c;

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}
int que(int id,int le,int ri){
	if(tree[id]<=val)return 0;
	if(le==ri)return le;
	int mid = le+ri>>1;
	if(a<=mid){
		int t1 = que(lc,le,mid);
		if(t1)return t1;
	}
	if(mid+1<=b)return que(rc,mid+1,ri);
	return 0;
}

inline ll g(ll x){
	return x*(x+1)/2;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>c;
		if(c=='1')++cnt, y[i] = 1;
		else {
			x[i-1] = cnt;
			cnt = 0;
		}
	}
	x[n] = cnt;
	rap(i,n,1)if(y[i])y[i] = y[i+1]+1;
	
	build(1,1,n);
	rap(i,n,1)if(x[i]){
		a = i+1, b = n, val = x[i];
		res = que(1,1,n);
		if(!res)dp[i] = (ll)x[i]*(n-i);
		else dp[i] = dp[res] + (ll)x[i]*(res-i) + g(x[res]-x[i]);
	}
	
	rep(i,1,n){
		a = i+y[i], b = n, val = y[i];
		res = a<=b ? que(1,1,n) : 0;
		ans+= g(y[i]);
		if(!res)ans+= (ll)val*(n-i-y[i]+1);
		else ans+= dp[res] + (ll)val*(res-i-y[i]+1) + g(x[res]-val);
	}
	cout<<ans<<endl;
    return 0;
}