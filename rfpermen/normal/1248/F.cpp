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
//#define ff fi.fi
//#define fs fi.se
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int tc,n,m,a,b,x,mx[MAX],z,cnt,tmp;
vector<int> v[MAX],u[MAX],aa,bb;
bool vx[MAX],vy[MAX];
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n){
    		v[i].clear();
			u[i].clear();
			mx[i] = i, vx[i] = vy[i] = 0;
		}
    	while(m--){
    		cin>>a>>b;
    		v[a].pb(b);
    		u[b].pb(a);
		}
		aa.clear(), bb.clear();
		rap(i,n,1){
			if(!vy[i])bb.pb(i), vy[i] = 1;
			while(!bb.empty()){
				tmp = bb.back(); bb.pob();
				for(int j:u[tmp]){
					mx[j] = max(mx[j],i);
					if(!vy[j])bb.pb(j), vy[j] = 1;
				}
			}
		}
//		rep(i,1,n)cout<<i<<" = "<<mx[i]<<endl;
		rep(i,1,n){
			if(mx[i]==i){
				aa.pb(i);
				vx[i] = 1;
				while(!aa.empty()){
					tmp = aa.back(); aa.pob();
					for(int j:v[tmp]){
						if(!vx[j])aa.pb(j), vx[j] = 1;
					}
				}
				break;
			}
		}
		cnt = 0;
		rep(i,1,n)cnt+=vx[i];
		if(cnt==n)cout<<"No\n";
		else {
			cout<<"Yes\n";
			cout<<cnt<<' '<<n-cnt<<endl;
			rep(i,1,n)if(vx[i])cout<<i<<' '; cout<<endl;
			rep(i,1,n)if(!vx[i])cout<<i<<' '; cout<<endl;
		}
	}
    return 0;
}