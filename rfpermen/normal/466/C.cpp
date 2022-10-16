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
const ll MAX=5e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,N,a,b,c,x[MAX],y[MAX],z,sz,cnt,tmp,ans,ttl;
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n; N = n-1;
    rep(i,1,n)cin>>x[i], ttl+=x[i], x[i]+=x[i-1];
    if(ttl%3)return cout<<0,0;
    ttl/=3;
    rep(i,2,N)y[i] = y[i-1] + (x[i]==2*ttl);
    //rep(i,1,n)cout<<y[i]<<endl;
    rep(i,1,N){
    	if(x[i]==ttl){
    		ans += y[N]-y[i];
		}
	}
	cout<<ans<<endl;
    return 0;
}