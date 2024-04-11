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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,n,m,a,b,c,cnt[MAX],ans[MAX],x,nx,hit;
vector<int> v[MAX],pos[MAX];
bool blk[MAX];
bool st,fn;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	m = n-2;
	rep(i,1,m){
		rep(j,1,3){
			cin>>x;
			++cnt[x];
			v[i].pb(x);
			pos[x].pb(i);
		}
	}
	st = 0;
	rep(i,1,n){
		if(cnt[i]==1){
			if(!st){
				ans[1] = i;
				fn = 0;
				rep(j,1,m){
					rep(k,0,2){
						if(v[j][k]==i){
							rep(o,0,2){
								if(cnt[v[j][o]]==2)ans[2] = v[j][o];
								else if(cnt[v[j][o]]==3)nx = v[j][o];
							}
							fn = 1; break;
						}
					}
					if(fn)break;
				}
			}
			else {
				ans[n] = i;
				fn = 0;
				rep(j,1,m){
					rep(k,0,2){
						if(v[j][k]==i){
							rep(o,0,2){
								if(cnt[v[j][o]]==2)ans[n-1] = v[j][o];
							}
							fn = 1; break;
						}
					}
					if(fn)break;
				}
			}
			st = 1;
		}
	}
	blk[ans[1]] = blk[ans[2]] = 1;
	rep(i,3,m){
		for(auto j:pos[nx]){
			hit = 0;
			for(auto k:v[j])if(blk[k])++hit;
			if(hit==1){
				ans[i] = nx;
				blk[nx] = 1;
				for(auto k:v[j])if(!blk[k])nx = k;
				break;
			}
		}
	}
	rep(i,1,n)cout<<ans[i]<<' '; cout<<endl;
    return 0;
}