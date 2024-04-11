#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int w,b;
double dp[MAX][MAX][2];
double f(int x,int y,bool st){
	if(!x)return 0;
	if(!y)return st;
	if(dp[x][y][st]>-1.0)return dp[x][y][st];
	if(st)return dp[x][y][st] = (f(x,y-1,st^1)*y+x)/(x+y);
	if(y>1)return dp[x][y][st] = ((f(x,y-2,st^1)*(y-1)+f(x-1,y-1,st^1)*x)/(x+y-1)*y)/(x+y);
	return dp[x][y][st] = (f(x-1,y-1,st^1)*y)/(x+y);
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>w>>b;
    rep(i,0,1000)rep(j,0,1000)rep(k,0,1)dp[i][j][k] = -1;
    cout<<f(w,b,1)<<endl;
	return 0;
}