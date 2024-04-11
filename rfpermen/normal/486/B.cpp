#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const ll MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,m;
bool a[105][105],b[105][105],st,r[105],c[105];

int main(){
	cout<<fixed<<setprecision(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>a[i][j];
    	if(!a[i][j])r[i]=1, c[j]=1;
	}
	memset(b,1,sizeof b);
	rep(i,1,n)if(r[i])rep(j,1,m)b[i][j] = 0;
	rep(j,1,m)if(c[j])rep(i,1,n)b[i][j] = 0;
	memset(r,0,sizeof r);
	memset(c,0,sizeof c);
	rep(i,1,n)rep(j,1,m)if(b[i][j])r[i]=1, c[j]=1;
	rep(i,1,n)rep(j,1,m){
		if(!a[i][j] && (r[i] || c[j]))return cout<<"NO",0;
		if(a[i][j] && !(r[i] || c[j]))return cout<<"NO",0;
	}
	cout<<"YES\n";
	rep(i,1,n){
		rep(j,1,m)cout<<b[i][j]<<" "; cout<<endl;
	}
    return 0;
}