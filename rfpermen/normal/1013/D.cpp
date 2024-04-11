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
const ll MAX=4e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,m,q,a,b,p[MAX],ans;
bool vis[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
	//cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    rep(i,1,n)p[i] = i;
    rep(i,1,m)p[i+n] = i+n;
    while(q--){
    	cin>>a>>b;
    	a = par(a), b = par(b+n);
    	p[a] = b;
	}
	n+=m;
	rep(i,1,n)vis[par(i)]=1;
	rep(i,1,n)if(vis[i])ans++;
	cout<<ans-1<<endl;
    return 0;
}