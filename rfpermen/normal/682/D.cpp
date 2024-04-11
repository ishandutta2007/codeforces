#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000003579;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,k,dp[MAX][MAX][11],le,ri,mid;
ll x[MAX],y[MAX],hs[MAX],key;
char s[MAX],t[MAX];

int f(int a,int b,int rem){
	if(!rem||a>n||b>m)return 0;
	if(dp[a][b][rem]!=-1)return dp[a][b][rem];
	if(s[a]!=t[b])return dp[a][b][rem] = max(f(a+1,b,rem),f(a,b+1,rem));
	int res;
	le = 1, ri = min(n-a,m-b), res = 0;
	while(le<=ri){
		mid = le+ri>>1;
		if(x[a+mid]-x[a-1]*hs[mid+1]!=y[b+mid]-y[b-1]*hs[mid+1])ri = mid-1;
		else res = mid, le = mid+1;
	}
	++res;
	return dp[a][b][rem] = max(res+f(a+res,b+res,rem-1),max(f(a+1,b,rem),f(a,b+1,rem)));
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    key = 10357;
    hs[0] = 1;
    rep(i,1,1000)hs[i] = hs[i-1]*key;
    cin>>n>>m>>k;
    rep(i,1,n){
    	cin>>s[i];
    	x[i] = x[i-1]*key + s[i];
	}
	rep(i,1,m){
		cin>>t[i];
		y[i] = y[i-1]*key + t[i];
	}
    memset(dp,-1,sizeof dp);
	cout<<f(1,1,k)<<endl;
	return 0;
}