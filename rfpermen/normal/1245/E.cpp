#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 20+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int x[MAX][MAX];
double dp[MAX][MAX];
bool vis[MAX][MAX];

double f(int r,int c){
	if(r==1){
		if(c==1)return 0.0;
		if(c<=7)return 6.0;
	}
	if(vis[r][c])return dp[r][c];
	vis[r][c] = 1;
	double ret = 0.0;
	rep(i,1,6){
		if(r&1){
			if(c>i)ret+= min(f(r,c-i),f(r-x[r][c-i],c-i));
			else ret+= min(f(r-1,i-c+1),f(r-1-x[r-1][i-c+1],i-c+1));
		}
		else {
			if(c+i<=10)ret+= min(f(r,c+i),f(r-x[r][c+i],c+i));
			else ret+= min(f(r-1,21-(c+i)),f(r-1-x[r-1][21-(c+i)],21-(c+i)));
		}
	}
	return dp[r][c] = ret/6.0 + 1.0;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,10)rep(j,1,10)cin>>x[i][j];
    cout<<f(10,1)<<endl;
    return 0;
}