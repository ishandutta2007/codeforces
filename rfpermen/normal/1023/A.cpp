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
const ll MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,til,nw;
char s[MAX],t[MAX],x[MAX];

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n>m+1)return cout<<"NO",0;
    rep(i,1,n)cin>>t[i];
    rep(i,1,m)cin>>s[i];
    til = max(n,m);
    rep(i,1,til){
    	if(s[i]!=t[i])break;
    	if(i==til)return cout<<"YES",0;
	}
	memset(x,0,sizeof x);
	til = 0;
	rep(i,1,n){
		if(t[i]!='*')x[i] = t[i];
		else {
			 til = i; break;
		}
	}
	if(!til)return cout<<"NO",0;
	nw = m, til++;
	rap(i,n,til)x[nw--] = t[i];
	rep(i,1,m){
		//cout<<x[i]<<endl;
		if(!x[i])continue;
		if(x[i]!=s[i])return cout<<"NO",0;
	}
	cout<<"YES";
    return 0;
}