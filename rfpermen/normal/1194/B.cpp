#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int tc,n,m,row[MAX],col[MAX],ans;
vector<bool> x[MAX];
char c;
//1194B
int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(i,1,50000)x[i].pb(0);
    while(tc--){
    	cin>>n>>m;
    	rep(i,1,n)row[i] = 0;
    	rep(i,1,m)col[i] = 0;
    	rep(i,1,n)rep(j,1,m){
    		cin>>c;
    		if(x[i].size()==j)x[i].pb(0);
    		x[i][j] = (c=='*');
    		row[i]+= x[i][j];
    		col[j]+= x[i][j];
		}
		ans = n+m;
		rep(i,1,n)rep(j,1,m)ans = min(ans,n+m - row[i] - col[j] - (!x[i][j]));
		cout<<ans<<endl;
	}
    return 0;
}