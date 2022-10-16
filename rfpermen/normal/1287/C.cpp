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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 100+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,x[MAX],dp[MAX][MAX>>1][MAX>>1][2],ans;

int f(int nw,int a,int b,bool st){
	if(a<0||b<0)return n;
	if(nw>n)return 0;
	int &ret = dp[nw][a][b][st];
	if(ret!=-1)return ret;
	if(x[nw])return ret = f(nw+1,a,b,x[nw]&1)+((x[nw]&1)!=st);
	return ret = min(f(nw+1,a-1,b,1)+!st,f(nw+1,a,b-1,0)+st);
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b;
    cin>>n; a = n+1>>1, b = n>>1;
    rep(i,1,n){
    	cin>>x[i];
    	if(x[i]){
    		if(x[i]&1)--a;
    		else --b;
		}
	}
	memset(dp,-1,sizeof dp);
	if(x[1])ans = f(2,a,b,x[1]&1);
	else {
		ans = n;
		if(a)ans = min(ans,f(2,a-1,b,1));
		if(b)ans = min(ans,f(2,a,b-1,0));
	}
	cout<<ans<<endl;
    return 0;
}