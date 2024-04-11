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
#define pdd pair<double,double>
#define endl "\n"
const ll MAX=2e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,x[105],y[105],z[105],c[105],sz,mul,res,cnt,mn;
bool st[105];
string s,t;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i]>>y[i]>>z[i]>>c[i];
    rep(i,1,n){
    	rep(j,1,n)if(x[i]<x[j] && y[i]<y[j] && z[i]<z[j])st[i] = 1;
	}
	mn = 1e9;
	rep(i,1,n)if(!st[i] && mn>c[i])mn = c[i], res = i;
	cout<<res;
    return 0;
}