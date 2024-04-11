#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,n,x[MAX],z,le,ri,mid,ans,nw;
pii nx[MAX];
priority_queue<pii> pq;
bool st;

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)x[i] = 0;
    	rep(i,1,n){
    		cin>>z;
    		++x[z];
		}
		le = 1, ri = n-2, ans = 0;
		while(le<=ri){
			mid = le+ri>>1;
			while(!pq.empty())pq.pop();
			rep(i,1,n){
				nx[i].fi = 0;
				if(x[i])pq.push({x[i],i});
			}
			st = 1;
			rep(i,1,n){
				if(nx[i].fi)pq.push(nx[i]);
				if(pq.empty()){
					st = 0;
					break;
				}
				z = pq.top().fi, nw = pq.top().se; pq.pop();
				nx[i+mid+1] = {z-1,nw};
			}
			if(st)ans = mid, le = mid+1;
			else ri = mid-1;
		}
		cout<<ans<<endl;
	}
    return 0;
}