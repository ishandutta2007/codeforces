#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
const int MAX = 3e4+5;
const ll MAX2 = 11;
const int MOD = 100000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n[2],k[2],dp[101][101][15][2];
ll f(int a,int b,int cnt,bool ls){
	if(cnt>k[ls])return 0;
	if(a<0||b<0)return 0;
	if(!a&&!b)return 1;
	if(dp[a][b][cnt][ls]!=-1)return dp[a][b][cnt][ls];
	if(ls)return dp[a][b][cnt][ls] = (f(a-1,b,1,0)+f(a,b-1,cnt+1,1))%MOD;
	return dp[a][b][cnt][ls] = (f(a-1,b,cnt+1,0)+f(a,b-1,1,1))%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n[0]>>n[1]>>k[0]>>k[1];
    memset(dp,-1,sizeof dp);
    cout<<f(n[0],n[1],0,0)<<endl;
	return 0;
}