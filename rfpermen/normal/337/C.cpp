#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 9;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,k,m,mul,ans,tmp,rem,z;

ll pw(ll x,ll y){
	if(y==0)return 1;
	if(y==1)return x;
	ll res = pw(x,y/2);
	res = (res*res)%MOD;
	if(y&1)return (res*x)%MOD;
	return res;
}

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k; m = n-m;
    if(m*k+k-1>=n)return cout<<n-m,0;
    rem = m*(k-1);
    n = n - m*k;
    z = n/k + 1;
    n%=k, n = k-n;
    mul = pw(2,z)-1;
    //cout<<mul<<" "<<z<<endl;
    ans = (mul*k-n+rem+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}