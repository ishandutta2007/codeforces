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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],nx[MAX][8],hs[MAX],dp[MAX][1<<8],le,ri,mid,ans;
vector<int> v[8];

int f(int nw,int mask){
	if(mask==255)return 0;
	if(dp[nw][mask]!=-1)return dp[nw][mask];
	int &ret = dp[nw][mask], pos; ret = -MOD;
	rep(i,0,7){
		if((mask&(1<<i)))continue;
		if(!nx[nw][i])return ret = -MOD;
		pos = hs[nx[nw][i]];
		if(pos+mid>=v[i].size())return ret = -MOD;
		ret = max(ret, f(v[i][pos+mid],mask|(1<<i)) + mid+1);
		if(pos+mid+1<v[i].size())ret = max(ret, f(v[i][pos+mid+1],mask|(1<<i)) + mid+2);
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], --x[i], hs[i] = v[x[i]].size(), v[x[i]].pb(i);
    rep(i,0,n)rep(j,i+1,n)if(!nx[i][x[j]])nx[i][x[j]] = j;
    rep(i,0,7)ans+=!v[i].empty();
    le = 0, ri = n/8;
    while(le<=ri){
    	memset(dp,-1,sizeof dp);
    	mid = le+ri>>1;
    	if(f(0,0)>0)ans = f(0,0), le = mid+1;
    	else ri = mid-1;
	}
	cout<<ans<<endl;
    return 0;
}