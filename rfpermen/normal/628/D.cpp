#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll m,d,n,dp[MAX][MAX][2],ans;
string a,b;
ll f(int nw,int rem,bool st){
	if(nw>n)return rem==0;
	if(dp[nw][rem][st]!=-1)return dp[nw][rem][st];
	if(nw&1){
		if(!st&&d>a[nw]-'0')return 0;
		return dp[nw][rem][st] = f(nw+1,(rem*10+d)%m,st|(d<a[nw]-'0'));
	}
	ll ret = 0;
	rep(i,0,9){
		if(!st&&i>a[nw]-'0')break;
		if(i==d)continue;
		ret = (ret+f(nw+1,(rem*10+i)%m,st|(i<a[nw]-'0')))%MOD;
	}
	return dp[nw][rem][st] = ret;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>d>>a>>b;
    n = a.size()-1;
    memset(dp,-1,sizeof dp);
    ans = f(0,0,0);
    int hit = 0;
    for(auto i:a)hit = (hit*10+i-'0')%m;
    if(hit==0){
    	bool cek = 1;
	    rep(i,0,n){
	    	if(i&1)if(a[i]-'0'!=d)cek = 0;
	    	if(i%2==0)if(a[i]-'0'==d)cek = 0;
		}
		ans-=cek;
	}
	a = b;
    memset(dp,-1,sizeof dp);
    cout<<(f(0,0,0)-ans+MOD)%MOD;
	return 0;
}