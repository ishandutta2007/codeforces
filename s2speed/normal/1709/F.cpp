#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 17 , md = 998244353 , inf = 2e16;

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

#define turn(x,v) x.resize(v)
int tr[maxn];
ll G = 3 , IG = tav(G , md - 2);
void Retry(int n)
{
	for(int i=0;i<n;i++)
	tr[i]=((tr[i>>1]>>1)|((i&1)?n>>1:0));
}
void NTT(vector<ll> &f,int opt)
{
	int n=sze(f);
	for(int i=0;i<n;i++)
	if(i<tr[i]) swap(f[i],f[tr[i]]);
	for(int len=2;len<=n;len<<=1)
	{
		ll w=tav(opt==1?G:IG,(md-1)/len);
		int l=(len>>1);
		for(int i=0;i<n;i+=len)
		{
			ll g=1;
			for(int j=i;j<i+l;j++)
			{
				ll v=g*f[j+l]%md;
				f[j+l]=(f[j]-v+md)%md;
				f[j]=(f[j]+v)%md;
				g=g*w%md;
			}
		}
	}
}
vector<ll> Mul(vector<ll> f,vector<ll> g)
{
	int n=sze(f),m=sze(g);
	int len=1;
	for(;len<=n+m-1;len<<=1);
	Retry(len);
	turn(f,len);turn(g,len);
	NTT(f,1);NTT(g,1);
	for(int i=0;i<len;i++)
	f[i]=f[i]*g[i]%md;
	NTT(f,-1);
	ll invn=tav(len,md-2);
	for(int i=0;i<len;i++)
	f[i]=f[i]*invn%md;
	turn(f,n+m-1);
	return f;
}

vector<ll> dp[17] , res , a , b;
ll sf[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k , f;
	cin>>n>>k>>f;
	for(ll i = 0 ; i < n ; i++) dp[i].assign(k + 1 , 0);
	dp[n].assign(k + 1 , 1);
	for(ll i = n - 1 ; i ; i--){
		memset(sf , 0 , sizeof(sf));
		res = Mul(dp[i + 1] , dp[i + 1]);
		ll rs = sze(res);
		for(ll j = k ; j < rs ; j++){
			sf[k] += res[j];
		}
		sf[k] %= md;
		for(ll j = min(rs , k - 1) ; ~j ; j--){
			sf[j] = sf[j + 1] + res[j]; sf[j] %= md;
		}
		ll lm = min(rs , k + 1);
		for(ll j = 0 ; j < lm ; j++){
			ll h = res[j] * (k - j) % md;
			dp[i][j] = h;
		}
		for(ll j = 0 ; j < lm ; j++){
			ll h = sf[j];
			dp[i][j] += h; dp[i][j] %= md;
		}
	}
	res = Mul(dp[1] , dp[1]);
	cout<<(f < sze(res) ? res[f] : 0)<<'\n';
	return 0;
}