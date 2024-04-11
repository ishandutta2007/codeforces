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
const int MAX = 2e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll tc,n,k[MAX],x[MAX][MAX],cnt[MAX],ans[MAX],mn,mx,rev[MAX];
vector<int> v;
bool st,vis[MAX];
set<int> cek;
 
int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	memset(cnt,0,sizeof cnt);
    	memset(vis,0,sizeof vis);
    	rep(i,2,n){
    		cin>>k[i];
    		rep(j,1,k[i])cin>>x[i][j], ++cnt[x[i][j]];
		}
		st = 1;
		rap(i,n,2){
			v.clear();
			rep(j,1,n)if(cnt[j]==1)v.pb(j);
			if(v.empty()){
				st = 0;
				break;
			}
			if(v.size()==2)ans[1] = v[1], cnt[v[1]]--;
			ans[i] = v[0];
			rep(j,2,n)if(!vis[j]){
				rep(o,1,k[j])if(x[j][o]==v[0])vis[j] = 1;
				
				if(vis[j]){
					rep(o,1,k[j])--cnt[x[j][o]];
					break;
				}
			}
		}
		if(st){
			cek.clear();
			rep(i,1,n)rev[ans[i]] = i;
			rep(i,2,n){
				mn = n, mx = 0;
				rep(j,1,k[i])mx = max(mx,rev[x[i][j]]), mn = min(mn,rev[x[i][j]]);
				if(cek.count(mx)||mx-mn+1!=k[i]){
					st = 0;
					break;
				}
				cek.insert(mx);
			}
		}
		
		if(!st){
			st = 1;
			memset(cnt,0,sizeof cnt);
    		memset(vis,0,sizeof vis);
    		rep(i,2,n)rep(j,1,k[i])++cnt[x[i][j]];
    		rap(i,n,2){
				v.clear();
				rep(j,1,n)if(cnt[j]==1)v.pb(j);
				if(v.empty()){
					st = 0;
					break;
				}
				if(v.size()==2)swap(v[0],v[1]), ans[1] = v[1], cnt[v[1]]--;
				ans[i] = v[0];
				rep(j,2,n)if(!vis[j]){
					rep(o,1,k[j])if(x[j][o]==v[0])vis[j] = 1;
					
					if(vis[j]){
						rep(o,1,k[j])--cnt[x[j][o]];
						break;
					}
				}
			}
			if(st){
				cek.clear();
				rep(i,1,n)rev[ans[i]] = i;
				rep(i,2,n){
					mn = n, mx = 0;
					rep(j,1,k[i])mx = max(mx,rev[x[i][j]]), mn = min(mn,rev[x[i][j]]);
					if(cek.count(mx)||mx-mn+1!=k[i]){
						st = 0;
						break;
					}
					cek.insert(mx);
				}
			}
			if(!st)return 1;
		}
		
		rep(i,1,n)cout<<ans[i]<<' '; cout<<endl;
	}
	return 0;
}