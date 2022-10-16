#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,m,k,jk[MAX],dp[105][MAX],ans,a,b,x[MAX],z[MAX];

void f(int rem,int l,int r,int optl,int optr){
	if(l>r)return;
	int mid = l+r>>1;
	ll opt = INF, c;
	int optid = mid;
	
	for(int i = optl; i<=mid && i<=optr; ++i){
		c = x[mid]*(mid-i+1) - (z[mid] - z[i-1]);
		if(dp[rem-1][i-1] + c < opt){
			opt = dp[rem-1][i-1] + c;
			optid = i;
		}
	}
	
	dp[rem][mid] = opt;
	f(rem , l , mid-1 , optl , optid);
	f(rem , mid+1 , r , optid, optr);
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,2,n)cin>>jk[i], jk[i]+=jk[i-1];
    rep(i,1,m){
    	cin>>a>>b;
		x[i] = b-jk[a];
	}
	sort(x+1,x+1+m);
	rep(i,1,m)z[i] = z[i-1] + x[i];
	rep(i,1,m)dp[1][i] = x[i]*i - z[i];
	rep(i,2,k)f(i,i,m,i,m);
	cout<<ans+dp[k][m]<<endl;
    return 0;
}