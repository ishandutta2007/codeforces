#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 4e3+5;
const ll MAX2 = 11;
const ll MOD = 1000003579;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,k,x[MAX][MAX],c[MAX][MAX],dp[805][MAX];
 
void f(int rem,int l,int r,int optl,int optr){
	if(l>r)return;
	int mid = l+r>>1;
	int opt = MOD, optid = mid;
	
	for(int i = optl; i<=mid && i<=optr; ++i){
		if(dp[rem-1][i-1] + c[i][mid] < opt){
			opt = dp[rem-1][i-1] + c[i][mid];
			optid = i;
		}
	}
	
	dp[rem][mid] = opt;
	f(rem , l , mid-1 , optl , optid);
	f(rem , mid+1 , r , optid, optr);
}
char C;
inline void in(int &num){
	do {
		C = getchar();
	}while(C>'9'||C<'0');
	num = 0;
	while(C>='0'&&C<='9'){
		num = num*10 + (C-'0');
		C = getchar();
	}
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    cin>>n>>k;
    in(n), in(k);
    rep(i,1,n){
    	rep(j,1,n){
//    		cin>>x[i][j];
    		in(x[i][j]);
    		if(j<=i)x[i][j] = 0;
    		x[i][j]+=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
		}
	}
	rep(i,1,n)rep(j,1,i)c[j][i] = x[i][i] - x[i][j-1] - x[j-1][i] + x[j-1][j-1];
	rep(i,1,n)dp[1][i] = c[1][i];
	rep(i,2,k)f(i,i,n,i,n);
	
	cout<<dp[k][n]<<endl;
	return 0;
}