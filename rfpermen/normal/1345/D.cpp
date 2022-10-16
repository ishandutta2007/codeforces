#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,m,p[MAX*MAX],r[MAX],c[MAX],cnt,a,b,ans;
char x[MAX][MAX];
bool aa,bb;
 
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}
 
int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j], p[(i-1)*m+j] = (i-1)*m+j;
    rep(i,1,n)rep(j,1,m)if(x[i][j]=='#'){
    	rep(k,0,1){
    		if(x[i+dr[k]][j+dc[k]]=='#'){
    			a = par((i-1)*m+j), b = par((i+dr[k]-1)*m+j+dc[k]);
//    			cout<<a<<' '<<b<<endl;
    			if(a==b)continue;
    			p[a] = b;
			}
		}
	}
	rep(i,1,n){
		rep(j,1,m)if(x[i][j]=='#'&&x[i][j]!=x[i][j-1])++r[i];
		if(r[i]>1)return cout<<"-1\n",0;
		if(!r[i])aa = 1;
	}
	rep(j,1,m){
		rep(i,1,n)if(x[i][j]=='#'&&x[i][j]!=x[i-1][j])++c[j];
		if(c[j]>1)return cout<<"-1\n",0;
		if(!c[j])bb = 1;
	}
	if(aa!=bb)return cout<<"-1\n",0;
	rep(i,1,n)rep(j,1,m)if((i-1)*m+j==par((i-1)*m+j)&&x[i][j]=='#')++ans;
	cout<<ans<<endl;
	return 0;
}