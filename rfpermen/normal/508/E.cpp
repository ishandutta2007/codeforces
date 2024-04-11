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
const int MAX = 2e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,dp[609][609],x[609],y[609];
char ans[1209];

bool f(int le,int ri){
	if(le>ri)return true;
	if(dp[le][ri]!=-1)return dp[le][ri];
	rep(i,x[le],y[le]){
		if(le+i>ri)break;
		if(f(le+1,le+i) && f(le+i+1,ri))return dp[le][ri] = true;
	}
	return dp[le][ri] = false;
}

void bt(int le,int ri,int pos){
	if(le>ri)return;
	ans[pos] = '(';
	rep(i,x[le],y[le]){
		if(f(le+1,le+i) && f(le+i+1,ri)){
			bt(le+1,le+i,pos+1), bt(le+i+1,ri,pos+i*2+2);
			ans[pos+i*2+1] = ')';
			break;
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i]>>y[i];
    	if(!(y[i]&1))--y[i];
    	x[i]>>=1, y[i]>>=1;
	}
	mems(dp,-1);
	if(f(1,n)){
		bt(1,n,1);
		n<<=1;
		rep(i,1,n)cout<<ans[i]; cout<<endl;
	}
	else cout<<"IMPOSSIBLE\n";
    return 0;
}