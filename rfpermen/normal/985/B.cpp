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
#define piii pair<int,pii>
//#define endl "\n"
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,m,x[2005][2005],pos,al[2005];
char c;
int main(){
    //cout<<fixed<<setprecision(3);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
    	rep(j,1,m)cin>>c,c-='0', x[i][j]=c, al[j]+=x[i][j];
	}
	rep(i,1,n){
		rep(j,1,m){
			if(al[j]-x[i][j]==0)break;
			if(j==m)return cout<<"YES",0;
		}
	}
	cout<<"NO";
    return 0;
}