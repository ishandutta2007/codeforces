#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
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
const int MAX=1<<18;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,id,hs[128],y,ans,o,a,b;
bool x[5300][5300],tmp[5300][5300],z[5300],ls,st;
string s;

int main(){
//	cout<<fixed<<setprecision(1);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,9)hs[i+'0'] = i;
    rep(i,0,5)hs[i+'A'] = i+10;
    cin>>n;
    rep(i,1,n){
    	cin>>s;
    	id = 0;
    	for(auto c:s){
    		y = hs[c], id+=4;
    		rep(j,0,3)x[i][id-j] = y&1, y>>=1;
		}
	}
//	rep(i,1,n){
//		rep(j,1,n)cout<<x[i][j];
//		cout<<endl;
//	}
	ans = 1;
	while(1){
		memset(z,0,sizeof z);
		st = 0;
		rep(k,2,n){
			if(n%k||z[k])continue;
			o = n/k-1;
			st = 1;
			rep(i,0,o)rep(j,0,o){
				if(!st)break;
				a = i*k, b = j*k;
				ls = x[a+1][b+1];
				rep(ii,1,k)rep(jj,1,k)if(x[ii+a][jj+b]!=ls)st = 0;
//				cout<<i<<' '<<j<<" -> "<<ls<<endl;
			}
//			cout<<n<<' '<<k<<' '<<st<<endl;
			if(st){
				n/=k;
				ans*=k;
				rep(i,1,n)rep(j,1,n)tmp[i][j] = x[(i-1)*k+1][(j-1)*k+1];
				rep(i,1,n)rep(j,1,n)x[i][j] = tmp[i][j];
				break;
			}
			else {
				rep(i,1,10000){
					if(i*k>n)break;
					z[i*k] = 1;
				}
			}
		}
		if(!st)break;
	}
	cout<<ans<<endl;
    return 0;
}