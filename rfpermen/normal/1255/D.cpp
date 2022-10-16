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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 100+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int tc,n,m,k,cnt,bis,tgt,id,a,b,dir,lkh;
char ans[MAX][MAX],x[MAX][MAX],hs[100];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,'0','9')hs[++id] = i;
    rep(i,'A','Z')hs[++id] = i;
    rep(i,'a','z')hs[++id] = i;
    cin>>tc;
    while(tc--){
    	cin>>n>>m>>k;
    	cnt = 0;
    	rep(i,0,n+1)rep(j,0,m+1)ans[i][j] = '#';
    	rep(i,1,n)rep(j,1,m){
    		cin>>x[i][j];
    		if(x[i][j]=='R')++cnt;
    		ans[i][j] = 0;
		}
		tgt = (cnt+k-1)/k;
		bis = cnt%k;
		id = 1;
		a = b = 1;
		dir = 0;
		lkh = n*m;
		cnt = 0;
		while(lkh--){
			ans[a][b] = hs[id];
			if(x[a][b]=='R'){
				++cnt;
				if(cnt==tgt){
					--bis;
					if(bis==0)--tgt;
					if(id!=k)++id;
					cnt = 0;
				}
			}
			if(!lkh)break;
			if(dir==0){
				if(ans[a][b+1])dir = 1, ++a;
				else ++b;
			}
			else if(dir==1){
				if(ans[a+1][b])dir = 2, --b;
				else ++a;
			}
			else if(dir==2){
				if(ans[a][b-1])dir = 3, --a;
				else --b;
			}
			else {
				if(ans[a-1][b])dir = 0, ++b;
				else --a;
			}
		}
		rep(i,1,n){
			rep(j,1,m)cout<<ans[i][j];
			cout<<endl;
		}
	}
    return 0;
}