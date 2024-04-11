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
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,a,b,nw,tmp;
bool st;
ll ans,hit,fact[MAX];

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
    fact[0] = 1;
    rep(i,1,1000000)fact[i] = (fact[i-1]*i)%MOD;
    cin>>a>>b>>n;
    nw = a*n;
    rep(i,0,n){
    	tmp = nw;
    	st = 1;
    	while(tmp && st){
    		if(tmp%10!=a && tmp%10!=b)st=0;
    		else tmp/=10;
		}
		nw+=b-a;
		if(!st)continue;
		hit = (pw(fact[i],MOD-2)*pw(fact[n-i],MOD-2))%MOD;
		hit = (hit*fact[n])%MOD;
		ans = (ans+hit)%MOD;
	}
	cout<<ans<<endl;
    return 0;
}