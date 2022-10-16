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
#define llc (id<<1)
#define rrc ((id<<1)|1)
#define lc(x) tree[x].le
#define rc(x) tree[x].ri
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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],pf[MAX],dp[MAX][MAX];

int f(int nw,int ls){
	if(nw==n)return 0;
	if(dp[nw][ls]!=-1)return dp[nw][ls];
	int tmp = pf[nw] - pf[ls-1], ret = f(nw+1,ls)+1;
	if(pf[n] - pf[nw] < tmp)return dp[nw][ls] = ret;
	int le = nw+1, ri = n, mid, res;
	while(le<=ri){
		mid = le+ri>>1;
		if(pf[mid] - pf[nw] >= tmp)res = mid, ri = mid-1;
		else le = mid+1;
	}
	return dp[nw][ls] = min(ret, f(res,nw+1) + (res-nw-1));
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], pf[i] = pf[i-1] + x[i];
    memset(dp,-1,sizeof dp);
    cout<<f(1,1)<<endl;
    return 0;
}