#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 131071;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,g[MAX],p[MAX],q[MAX],pos[MAX],cnt,sz[MAX],dep[MAX],v[MAX],a,b,mv,ans,nw,nx;

int par(int *p,int z){
	if(p[z]==z)return z;
	return p[z] = par(p,p[z]);
}

int f(int nw){
	if(dep[nw]!=-1)return dep[nw];
	return dep[nw] = f(g[nw])+1;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)p[i] = i;
    memset(dep,-1,sizeof dep);
    rep(i,1,n){
    	cin>>g[i];
    	a = i, b = par(p,g[i]);
		if(a==b){
			cnt = 0;
			while(dep[a]==-1)dep[a] = 0, pos[a] = ++cnt, a = g[a];
			nw = a;
			do{
				sz[nw] = cnt;
				nw = g[nw];
			}while(nw!=a);
		}
		else p[a] = b;
	}
	rep(i,1,n)f(i), p[i] = q[i] = i;
	rep(i,1,m)cin>>v[i];
	
	rep(i,1,m){
		cin>>mv;
		nw = (v[i] + ans - 1)%n + 1, ans = 0;
		
		while(mv>0&&dep[nw]!=0){
			nx = par(q,nw);
			if(nx==nw){
				++ans;
				nx = par(q,g[nw]);
				q[nw] = nx;
			}
			mv-= dep[nw]-dep[nx];
			nw = nx;
		}
		
		while(mv>0){
			nx = par(p,nw);
			if(!nx)break;
			if(nx==nw){
				++ans;
				nx = par(p,g[nw]);
				if(nx==nw){
					p[nw] = 0;
					break;
				}
				p[nw] = nx;
			}
			mv-= (pos[nx] - pos[nw] + sz[nw])%sz[nw];
			nw = nx;
		}
		
		cout<<ans<<endl;
	}
    return 0;
}