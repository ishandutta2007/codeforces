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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000003579;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,k,ans,mx,tmp,r[MAX][MAX],c[MAX][MAX],cnt;
char x[MAX][MAX];
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)rep(j,1,n)cin>>x[i][j];
    rep(i,1,n){
    	cnt = 0;
    	rep(j,1,n)if(x[i][j]=='B')++cnt;
    	if(!cnt){++ans; continue;}
    	rap(j,k-1,1)if(x[i][j]=='B')--cnt;
    	rep(j,k,n){
    		if(x[i][j]=='B')--cnt;
    		if(!cnt)c[i][j-k+1] = 1;
    		if(x[i][j-k+1]=='B')break;
		}
	}
	rep(j,1,n)rep(i,1,n)c[i][j]+=c[i-1][j];
	
    rep(j,1,n){
    	cnt = 0;
    	rep(i,1,n)if(x[i][j]=='B')++cnt;
    	if(!cnt){++ans; continue;}
    	rap(i,k-1,1)if(x[i][j]=='B')--cnt;
    	rep(i,k,n){
    		if(x[i][j]=='B')--cnt;
    		if(!cnt)r[i-k+1][j] = 1;
    		if(x[i-k+1][j]=='B')break;
		}
	}
	rep(i,1,n)rep(j,1,n)r[i][j]+=r[i][j-1];
//	rep(i,1,n){
//		rep(j,1,n)cout<<r[i][j]<<' ';
//		cout<<endl;
//	}
	
	n = n-k+1;
	rep(i,1,n)rep(j,1,n){
		mx = max(mx,c[i+k-1][j]-c[i-1][j] + r[i][j+k-1]-r[i][j-1]);
	}
	cout<<ans+mx<<endl;
	return 0;
}