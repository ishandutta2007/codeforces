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
const int MAX = 120+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,cnt[MAX],x[MAX],m;
int vis[MAX][MAX],nw,ls,mn,ans;
vector<int> v[MAX];
queue<pii> q;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m;
    rep(i,1,m){
    	++n;
    	cin>>x[n];
    	if(!x[n]){--n; continue;}
    	if(n==121)return cout<<"3\n",0;
    	rep(j,0,59)if(x[n]&(1ll<<j))cnt[j]++;
	}
    rep(i,0,59)if(cnt[i]>2)return cout<<"3\n",0;
    rep(i,1,n){
    	rep(j,1,n){
    		if(i==j)continue;
    		if(x[i]&x[j])v[i].pb(j);
		}
	}
	mn = 1e9;
	rep(i,1,n){
		while(!q.empty())q.pop();
		memset(vis,0,sizeof vis);
		vis[i][0] = 1;
		q.push({i,0});
		ans = 0;
		while(!q.empty()){
			nw = q.front().fi, ls = q.front().se; q.pop();
			for(auto j:v[nw]){
				if(j==ls)continue;
				if(j==i){
					ans = vis[nw][ls];
					break;
				}
				if(vis[j][nw])continue;
				vis[j][nw] = vis[nw][ls]+1;
				q.push({j,nw});
			}
			if(ans)break;
		}
		if(ans)mn = min(ans,mn);
	}
	if(mn>60)cout<<"-1\n";
	else cout<<mn<<endl;
	return 0;
}