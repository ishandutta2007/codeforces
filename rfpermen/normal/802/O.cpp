#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

ll n,k,x[MAX],y[MAX],le,ri,mid,res;
priority_queue<pll> pq;

pll f(ll lambda){
	ll ret = 0, cnt = 0;
	rep(i,1,n){
		ret+= x[i];
		pq.push({-x[i],0});
		pq.push({y[i]-lambda,1});
		pq.pop();
	}
	rep(i,1,n){
		ret+= pq.top().fi;
		cnt+= pq.top().se;
		pq.pop();
	}
	return {ret,cnt};
}

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>y[i];
    le = 0, ri = 10e10;
    while(le<=ri){
    	mid = le+ri>>1;
    	if(f(mid).se<=k)res = mid, le = mid+1;
    	else ri = mid-1;
	}
//	cout<<f(res).fi<<' '<<f(res).se<<' '<<res<<endl;
	cout<<f(res).fi+res*k<<endl;
	return 0;
}