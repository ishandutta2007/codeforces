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
const int MAX = 3e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,k,a,b,c,d,sz,y,z;
char x[MAX][MAX];
vector<pii> v[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    rep(i,1,n)rep(j,1,m){
    	if(x[i][j]!='*')continue;
    	a = b = j, c = d = i;
    	sz = 0;
    	while(a>1&&b<m&&c>1&&d<n){
    		--a, ++b, --c, ++d, ++sz;
    		if(x[i][a]=='*' && x[i][b]=='*' && x[c][j]=='*' && x[d][j]=='*')v[sz].pb({i,j});
		}
	}
	rep(i,1,300){
		if(k>v[i].size())k-=v[i].size();
		else {
			sort(all(v[i]));
			y = v[i][k-1].fi, z = v[i][k-1].se;
			cout<<y<<' '<<z<<endl;
			cout<<y-i<<' '<<z<<endl;
			cout<<y+i<<' '<<z<<endl;
			cout<<y<<' '<<z-i<<endl;
			cout<<y<<' '<<z+i<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
    return 0;
}