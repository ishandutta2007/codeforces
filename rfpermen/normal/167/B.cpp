#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 2e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,l,k;
double dp[MAX][MAX][MAX];
pair<int,double> per[MAX];
bool vis[MAX][MAX][MAX];

double f(int nw,int win,int rem){
	if(rem<0)return 0.0;
	if(nw>n)return (double)(win>=l);
	if(vis[nw][win][rem])return dp[nw][win][rem];
	vis[nw][win][rem] = 1;
	double ret;
	if(per[nw].fi==-1)ret = f(nw+1,win+1,rem-1)*per[nw].se + f(nw+1,win,rem)*(1.0-per[nw].se);
	else ret = f(nw+1,win+1,min(n,rem+per[nw].fi))*per[nw].se + f(nw+1,win,rem)*(1.0-per[nw].se);
	return dp[nw][win][rem] = ret;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>k;
    rep(i,1,n)cin>>per[i].se, per[i].se/=100.0;
    rep(i,1,n)cin>>per[i].fi;
    sort(per+1,per+1+n);
    reverse(per+1,per+1+n);
    cout<<f(1,0,k)<<endl;
    return 0;
}