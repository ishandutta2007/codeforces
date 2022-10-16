#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,q,a,b,cnt[128],x[MAX],id,hs[55][55],hs2[55][55],tf[128],tmp, dp[1327][MAX>>1], mem[1327][MAX>>1];
ll f[MAX], pre[MAX], res, ans[55][55];
string s;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int g(int a,int b,int rem){
	if(!rem)return 1;
	if(rem<0 || a>b)return 0;
	if(a==b)return rem==x[a];
	int &ret = dp[hs[a][b]][rem];
	if(ret!=-1)return ret;
	ret = g(a+1,b,rem) + g(a+1,b,rem-x[a]);
	if(ret>=MOD)ret-= MOD;
	return ret;
}

int h(int a,int b,int rem){
	if(rem<0)return 0;
	if(!a && b>id)return rem==0;
	int &ret = mem[hs2[a][b]][rem];
	if(ret!=-1)return ret;
	
	if(a)ret = h(a-1,b,rem) + h(a-1,b,rem-x[a]);
	else ret = h(a,b+1,rem) + h(a,b+1,rem-x[b]);
	if(ret>=MOD)ret-= MOD;
	
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(5);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = pre[0] = 1;
    rep(i,1,100000)f[i] = f[i-1]*i%MOD, pre[i] = pw(f[i],MOD-2);
    cin>>s>>q;
    n = s.size(), m = n/2;
    for(auto i:s)cnt[i]++;
    s = 's'+s;
    res = f[m]*f[m]%MOD;
    rep(i,0,127)res = res*pre[cnt[i]]%MOD;
    
    memset(dp,-1,sizeof dp);
    memset(mem,-1,sizeof mem);
    
    rep(i,1,52)rep(j,i+1,52)hs[i][j] = ++id;
    id = 0;
    rep(i,0,52)rep(j,i+3,53)hs2[i][j] = ++id;
    id = 0;
    
    rep(i,0,25){
    	if(cnt[i+'A'])x[++id] = cnt[i+'A'], tf[i+'A'] = id;
		if(cnt[i+'a'])x[++id] = cnt[i+'a'], tf[i+'a'] = id;
	}
	
	rep(i,1,id)rep(j,i+1,id){
		tmp = m-x[i]-x[j];
		rep(k,0,tmp)ans[i][j] = (ans[i][j] + (ll)g(i+1,j-1,k)*h(i-1,j+1,tmp-k))%MOD;
		ans[i][j] = (ans[i][j]*res<<1) % MOD;
	}
	res = res*g(1,id,m)%MOD;
	
    while(q--){
    	cin>>a>>b;
    	if(s[a]==s[b]){cout<<res<<endl; continue;}
    	
    	if(tf[s[a]]>tf[s[b]])swap(a,b);
    	cout<<ans[tf[s[a]]][tf[s[b]]]<<endl;
	}
	return 0;
}