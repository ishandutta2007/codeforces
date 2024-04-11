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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 15+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,a,b,x[MAX],dp[MAX][MAX][MAX];
vector<int> ans;

int f(int nw,int pvv,int pv){
	if(pvv<0)pvv = 0;
	if(pv<0)pv = 0;
	if(nw==n+1)return (pvv ? 1e9 : 0);
	if(dp[nw][pvv][pv]!=-1)return dp[nw][pvv][pv];
	int &ret = dp[nw][pvv][pv];
	ret = 1e9;
	rep(i,0,15){
		if(pvv<=0)ret = min(ret,f(nw+1,pv,x[nw]-b*i)+i);
		pv-=a, pvv-=b;
	}
	return ret;
}

void bt(int nw,int pvv,int pv){
	if(pvv<0)pvv = 0;
	if(pv<0)pv = 0;
	if(nw==n+1)return;
	int ret = dp[nw][pvv][pv];
	rep(i,0,15){
		if(pvv<=0){
			if(ret==f(nw+1,pv,x[nw]-b*i)+i){
				bt(nw+1,pv,x[nw]-b*i);
				break;
			}
		}
		ans.pb(nw-1);
		pv-=a, pvv-=b;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    rep(i,1,n)cin>>x[i], ++x[i];
    while(x[1]>0)ans.pb(2), x[1]-=b, x[2]-=a, x[3]-=b;
    while(x[n]>0)ans.pb(n-1), x[n-2]-=b, x[n-1]-=a, x[n]-=b;
    memset(dp,-1,sizeof dp);
    f(3,x[1],x[2]);
//    db(f(3,x[1],x[2]));
    bt(3,x[1],x[2]);
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
    return 0;
}