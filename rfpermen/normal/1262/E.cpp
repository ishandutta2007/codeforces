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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,le,ri,mid,ans,z,tgt;
vector<int> x[MAX],y[MAX],pre[MAX],res[MAX];
char c;
bool st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,0,n)rep(j,0,m)x[i].pb(0), y[i].pb(0), pre[i].pb(0), res[i].pb(0);
    rep(i,1,n)rep(j,1,m){
    	cin>>c;
    	y[i][j] = y[i-1][j] + y[i][j-1] - y[i-1][j-1];
    	if(c=='X')++y[i][j], x[i][j] = res[i][j] = 1;
	}
	int x1,x2,y1,y2;
	le = 1, ri = min(n,m)>>1;
	while(le<=ri){
		mid = le+ri>>1;
		z = mid+mid+1;
		tgt = z*z;
		rep(i,1,n)rep(j,1,m)pre[i][j] = 0;
		rep(i,z,n)rep(j,z,m){
			if(y[i][j] - y[i-z][j] - y[i][j-z] + y[i-z][j-z] == tgt)pre[i-mid][j-mid] = 1;
		}
		rep(i,1,n)rep(j,1,m)pre[i][j]+= pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		st = 1;
		rep(i,1,n){
			if(!st)break;
			rep(j,1,m){
				if(x[i][j]){
					x1 = max(0,i-mid-1), x2 = min(n,i+mid);
					y1 = max(0,j-mid-1), y2 = min(m,j+mid);
					if(pre[x2][y2] - pre[x1][y2] - pre[x2][y1] + pre[x1][y1] == 0){
						st = 0;
						break;
					}
				}
			}
		}
		if(st){
			ans = mid, le = mid+1;
			rep(i,1,n)rep(j,1,m)res[i][j] = pre[i][j] - pre[i-1][j] - pre[i][j-1] + pre[i-1][j-1];
		}
		else ri = mid-1;
	}
	cout<<ans<<endl;
	rep(i,1,n){
		rep(j,1,m)cout<<(res[i][j] ? 'X' : '.');
		cout<<endl;
	}
    return 0;
}