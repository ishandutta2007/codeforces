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
#define ff fi.fi
#define fs fi.se
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n, x[MAX], z[MAX][MAX], res, y;
bool st;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>z[i][j];
    rep(i,2,n)res = __gcd(res,z[1][i]);
    y = sqrt(res);
    rep(i,1,y){
    	if(res%i)continue;
    	x[1] = i;
    	rep(a,2,n)x[a] = z[1][a]/x[1];
    	st = 1;
    	rep(a,1,n)rep(b,1,n){
    		if(!st)break;
    		if(a==b)continue;
    		if(z[a][b]!=x[a]*x[b])st = 0;
		}
		if(st){
			rep(j,1,n)cout<<x[j]<<' ';
			return 0;
		}
		
		x[1] = res/i;
    	rep(a,2,n)x[a] = z[1][a]/x[1];
    	st = 1;
    	rep(a,1,n)rep(b,1,n){
    		if(!st)break;
    		if(a==b)continue;
    		if(z[a][b]!=x[a]*x[b])st = 0;
		}
		if(st){
			rep(j,1,n)cout<<x[j]<<' ';
			return 0;
		}
	}
	return 1;
	return 0;
}