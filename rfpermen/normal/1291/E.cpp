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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,m,a,b,c,d,k,p[MAX],sz[MAX],st[MAX],lw[MAX],ans;
bool z[MAX],vis[MAX];
char cc;
vector<int> v[MAX];
 
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void merge(int x,int y){
	p[y] = x;
	sz[x]+= sz[y];
	if(st[y]!=1)st[x] = st[y];
	if(!lw[x])lw[x] = lw[y];
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>cc, z[i] = (cc=='1');
    rep(i,1,k)p[i] = i, sz[i] = st[i] = 1;
    rep(i,1,k){
    	cin>>m;
    	while(m--){
    		cin>>a;
    		v[a].pb(i);
		}
	}
	rep(i,1,n){
		if(v[i].size()==1){
			a = par(v[i][0]), b = par(lw[a]);
//			if(b)assert(vis[a]!=vis[b]);
			if(z[i]){
				st[a] = 0;//pasti gak pake
				if(b){
					assert(st[b]!=0);
					st[b] = 2;
				}
				if(vis[a]){
					ans-= sz[a] - sz[b];
					vis[a] = 0;
					assert(b);
					vis[b] = 1;
				}
			}
			else {
				st[a] = 2;//pasti pake
				if(b){
					assert(st[b]!=2);
					st[b] = 0;
				}
				if(!vis[a]){
					ans+= sz[a] - sz[b];
					vis[a] = 1, vis[b] = 0;
				}
			}
		}
		else if(v[i].size()==2){
			a = par(v[i][0]), b = par(v[i][1]);
			c = par(lw[a]), d = par(lw[b]);
			if(c)assert(vis[a]!=vis[c]);
			if(d)assert(vis[d]!=vis[b]);

			if(!z[i]){
				if(!c)lw[a] = c = b;
				if(!d)lw[b] = d = a;
				//nanti cek lagi pake assert
//				if(st[a]!=1)st[c] = st[a]^2;
//				if(st[d]!=1)st[b] = st[d]^2;
//				cout<<">> "<<st[a]<<' '<<st[b]<<' '<<st[c]<<' '<<st[d]<<endl;
				swap(b,d);
			}
			
			if(vis[a])ans-= sz[a], vis[a] = 0;
			if(vis[b])ans-= sz[b], vis[b] = 0;
			if(vis[c])ans-= sz[c], vis[c] = 0;
			if(vis[d])ans-= sz[d], vis[d] = 0;
			
			if(a!=b)merge(a,b);
			
			if(c||d){//berarti harus ada yg nyala
				if(c<d)swap(c,d);
				if(c!=d&&d)merge(c,d);
				if(st[c]!=1)st[a] = st[c]^2;
				if(st[a]!=1){
					st[c] = st[a]^2;
//					cout<<a<<' '<<c<<" = "<<st[a]<<' '<<st[c]<<endl;
//					assert(abs(st[a]-st[c])==2);
					if(st[a]==2)ans+= sz[a], vis[a] = 1;
					else ans+= sz[c], vis[c] = 1;
				}
				else {
					if(sz[a]<sz[c])ans+= sz[a], vis[a] = 1;
					else ans+= sz[c], vis[c] = 1;
				}
			}
			else if(st[a]==2)ans+= sz[a], vis[a] = 1;
		}
		cout<<ans<<endl;
	}
    return 0;
}