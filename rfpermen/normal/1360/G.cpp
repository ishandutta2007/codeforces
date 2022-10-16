#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 50+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,n,m,a,b,x,y,dx,dy;
char ans[MAX][MAX];
bool st;

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m>>a>>b;
    	if(n*a!=m*b){cout<<"NO\n"; continue;}
    	cout<<"YES\n";
    	x = y = 1, st = 0;
    	memset(ans,'0',sizeof ans);
    	while(x<=n&&y<=m){
    		if((n-b-x+1>=b&&m-a-y+1>=a)||(x+b>n&&y+a>m)){
    			dx = x+b-1, dy = y+a-1;
    			rep(i,x,dx)rep(j,y,dy)ans[i][j] = '0' + (st^1);
    			x+=b, y+=a;
			}
			else {
				st^=1;
				a = (m-y+1)-a, b = (n-x+1)-b;
				rep(i,x,n)rep(j,y,m)ans[i][j] = '0' + st;
			}
		}
		rep(i,1,n){
			rep(j,1,m)cout<<ans[i][j]; cout<<endl;
		}
	}
    return 0;
}