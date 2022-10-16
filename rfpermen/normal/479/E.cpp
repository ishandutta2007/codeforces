#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,a,b,k,x[MAX],ds,pos;
ll dp[2][MAX],val[MAX],ans;
bool ls,nw;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b>>k;
    if(a>b)a = n-a+1, b = n-b+1;
    
    asd(i,1,b){
    	ds = b-i-1;
    	pos = i;
    	while(ds--){
    		pos--;
    		if(!pos)break;
    		x[pos] = i;
		}
	}
	asd(i,1,b)if(!x[i])x[i] = i-1;
	
	asd(i,a,b)dp[1][i] = 1;
	val[a] = 1;
	ls = 1;
	rep(iter,1,k){
		mems(dp[nw],0);
		asd(i,1,b){
			val[i] = dp[ls][x[i]]-(x[i]>=i?val[i]:0);
			if(val[i]<0)val[i]+= MOD;
			dp[nw][i] = dp[nw][i-1] + val[i];
			if(dp[nw][i]>=MOD)dp[nw][i]-= MOD;
		}
		nw^= 1, ls^= 1;
	}
	cout<<dp[ls][b-1]<<endl;
    return 0;
}