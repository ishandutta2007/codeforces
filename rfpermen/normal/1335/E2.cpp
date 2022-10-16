#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int tc,n,cnt[MAX][205],c,ans,sz,mx,a,b;
vector<int> pos[205];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	rep(i,1,n)memset(cnt[i],0,sizeof cnt[i]);
    	rep(i,1,200)pos[i].clear();
    	rep(i,1,n){
    		cin>>c;
    		rep(j,1,200)cnt[i][j] = cnt[i-1][j];
    		cnt[i][c]++;
    		pos[c].pb(i);
		}
		ans = 0;
		rep(i,1,200){
			if(pos[i].empty())continue;
			ans = max(ans,(int)pos[i].size());
			sz = pos[i].size()-1;
			rep(j,0,sz){
				if(j>=sz-j)break;
				a = pos[i][j], b = pos[i][sz-j]-1;
				mx = 0;
				rep(k,1,200)mx = max(mx,cnt[b][k]-cnt[a][k]);
				ans = max(ans,(j+1<<1)+mx);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}