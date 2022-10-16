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
const int MAX = 5e2+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={-1,0,1,0,1,1,-1,-1,0};
const int dc[]={0,-1,0,1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 320;

ll tc,n,m,p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},k=15,ans;
__int128 bt,nw;

void bf(int pos,int ls,ll rem){
	if(rem==1){
		if(ans==-1)ans = nw;
		else ans = min(ans,(ll)nw);
		return;
	}
	if(pos==k)return;
	__int128 mul = 1;
	ls = min((ll)ls,rem);
	rep(i,2,ls){
		mul*= p[pos];
		if(mul*nw>bt)break;
		if(rem%i==0)nw*=mul, bf(pos+1,i,rem/i), nw/= mul;
	}
	return;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("xot.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    m = 1000000000000000000;
	ans = -1;
	bt = m, nw = 1;
	bf(0,61,n);
	cout<<ans<<endl;
    return 0;
}