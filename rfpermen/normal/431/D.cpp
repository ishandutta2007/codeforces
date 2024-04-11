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
#define ff fi.fi
#define fs fi.se
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
const int MAX = 5e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;

ll m,k,z,le,ri,mid,ans,dp[69][69][2],res;

ll f(int nw,int cnt,bool st){
	if(nw<0)return cnt==k;
	ll &ret = dp[nw][cnt][st];
	if(ret!=-1)return ret;
	if(st)ret = f(nw-1,cnt,st) + f(nw-1,cnt+1,st);
	else {
		if(z&(1LL<<nw))ret = f(nw-1,cnt,1) + f(nw-1,cnt+1,0);
		else ret = f(nw-1,cnt,0);
	}
	return ret;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>k;
    if(k>60)return cout<<"1\n",0;
    le = 1, ri = 1e18;
    while(le<=ri){
    	mid = le+ri>>1;
    	z = mid<<1, mems(dp,-1);
    	res = f(60,0,0);
    	z = mid, mems(dp,-1);
    	res-= f(60,0,0);
    	if(res>=m)ans = mid, ri = mid-1;
    	else le = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}