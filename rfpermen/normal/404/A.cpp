#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c[128],x,y,z,sz,T;
string s,t;
char g[333][333];
int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>g[i][j], c[g[i][j]]++;
    if(g[1][1]==g[1][2])return cout<<"NO",0;
    rep(i,2,n)if(g[i][i]!=g[i-1][i-1])return cout<<"NO",0;
    rep(i,2,n)if(g[i][n-i+1]!=g[i-1][n-i+2])return cout<<"NO",0;
    if(c[g[1][1]]+c[g[1][2]]!=n*n || c[g[1][1]]!=2*n-1)return cout<<"NO",0;
    cout<<"YES";
    return 0;
}