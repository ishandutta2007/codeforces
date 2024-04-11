#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e7+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,z,x[MAX],y[MAX],pr[500],cnt;
bool p[MAX];
vector<int> a[MAX];

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 2; i*i<=10000000; ++i){
    	if(p[i])continue;
    	pr[++cnt] = i;
    	for(int j = i*i; j<=10000000; j+=i)p[j] = 1;
	}
	cin>>n>>m;
	rep(i,1,n){
		cin>>x[i];
		z = x[i];
		rep(j,1,cnt){
			if(!p[z]){
				a[z].pb(i);
				break;
			}
			if(pr[j]*pr[j]>z)break;
			while(z%pr[j]==0)z/=pr[j], a[pr[j]].pb(i);
		}
	}
	rep(i,1,m){
		cin>>y[i];
		z = y[i];
		rep(j,1,cnt){
			if(!p[z]){
				if(!a[z].empty()){
					x[a[z].back()]/=z;
					y[i]/=z;
					a[z].pob();
				}
				break;
			}
			if(pr[j]*pr[j]>z)break;
			while(z%pr[j]==0){
				z/=pr[j];
				if(!a[pr[j]].empty()){
					x[a[pr[j]].back()]/=pr[j];
					a[pr[j]].pob();
					y[i]/=pr[j];
				}
			}
		}
	}
	cout<<n<<' '<<m<<endl;
	rep(i,1,n)cout<<x[i]<<' '; cout<<endl;
	rep(i,1,m)cout<<y[i]<<' '; cout<<endl;
	return 0;
}