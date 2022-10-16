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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int tc,n,ans[MAX],x[MAX],a,b;
char c;
bool st;

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n;
		rep(i,1,n)cin>>c, x[i] = c-'0';
		st = 0;
		rep(k,0,8){
			a = b = 0;
			st = 1;
			rep(i,1,n){
				if(x[i]<k){
					if(a>x[i]){
						st = 0; break;
					}
					ans[i] = 1;
					a = x[i];
				}
				else {
					if(b>x[i]){
						if(x[i]!=k){
							st = 0; break;
						}
						ans[i] = 1;
						a = x[i];
					}
					else ans[i] = 2, b = x[i];
				}
			}
			if(st)break;
		}
		if(st){
			rep(i,1,n)cout<<ans[i]; cout<<endl;
		}
		else cout<<"-\n";
	}
	return 0;
}