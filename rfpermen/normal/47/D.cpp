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
 
int n,z,y[15],tmp;
char c;
bool x[15][40];
map<int,int> dp[40];
 
ll f(int pos,int mask){
	if(pos>n)return mask==0;
	if(dp[pos].count(mask))return dp[pos][mask];
	int a[11], &ret = dp[pos][mask];
	rep(i,1,z)a[i] = mask%6, mask/=6;
	rap(i,z,1){
		if(x[i][pos])mask = mask*6 + a[i];
		else if(!a[i]){mask = -1; break;}
		else mask = mask*6 + a[i]-1;
	}
	if(mask!=-1)ret+= f(pos+1,mask);
	mask = 0;
	rap(i,z,1){
		if(!x[i][pos])mask = mask*6 + a[i];
		else if(!a[i]){mask = -1; break;}
		else mask = mask*6 + a[i]-1;
	}
	if(mask!=-1)ret+= f(pos+1,mask);
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>z;
    rep(i,1,z){
    	rep(j,1,n)cin>>c, x[i][j] = c-'0';
    	cin>>y[i];
	}
	rap(i,z,1)tmp = tmp*6 + y[i];
	cout<<f(1,tmp)<<endl;
    return 0;
}