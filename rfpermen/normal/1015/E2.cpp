#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,m,le,ri,mid,mx,hit;
char c;
bool x[MAX][MAX];
int a[MAX][MAX],b[MAX][MAX],aa[MAX][MAX],bb[MAX][MAX];
vector<piii> ans;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>c;
    	if(c=='*')x[i][j] = 1;
    	a[i][j] = a[i-1][j]+x[i][j], b[i][j] = b[i][j-1]+x[i][j];
	}
	rep(i,1,n)rep(j,1,m){
		if(!x[i][j])continue;
		le = 1, ri = min(min(i,j)-1,min(n-i,m-j)), mx = 0;
		while(le<=ri){
			mid = le+ri>>1;
			if(b[i][j+mid]-b[i][j-mid-1]!=mid*2+1||a[i+mid][j]-a[i-mid-1][j]!=mid*2+1)ri = mid-1;
			else le = mid+1, mx = mid;
		}
		if(mx){
			aa[i-mx][j]++, bb[i][j-mx]++;
			aa[i+mx+1][j]--, bb[i][j+mx+1]--;
			ans.pb({i,{j,mx}});
		}
	}
	rep(i,1,n){
		hit = 0;
		rep(j,1,m){
			hit+=bb[i][j];
			if(hit)x[i][j] = 0;
		}
	}
	rep(j,1,m){
		hit = 0;
		rep(i,1,n){
			hit+=aa[i][j];
			if(hit)x[i][j] = 0;
		}
	}
	rep(i,1,n)rep(j,1,m)if(x[i][j])return cout<<"-1\n",0;
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.fi<<' '<<i.sf<<' '<<i.ss<<endl;
	return 0;
}