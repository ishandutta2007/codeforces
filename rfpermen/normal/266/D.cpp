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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,a,b,c,v[205][205],ans;
pair<double,pii> e[205*205];
double le,ri,m1,m2,n1,n2,a1,a2,u[205][205],nx;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,n)if(i!=j)v[i][j] = MOD;
    rep(i,1,m){
    	cin>>a>>b>>c;
    	e[i] = {c,{a,b}};
    	v[a][b] = v[b][a] = min(v[a][b],c);
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
	rep(i,1,n)rep(j,1,n)u[i][j] = v[i][j];
	ans = 1e9;
	rep(i,1,m){
		a = e[i].sf, b = e[i].ss;
		le = 0.0, ri = e[i].fi;
		rep(k,1,30){
			m1 = (le+le+ri)/3.0, n1 = e[i].fi - m1;
			m2 = (le+ri+ri)/3.0, n2 = e[i].fi - m2;
			a1 = a2 = 0.0;
			rep(j,1,n){
				a1 = max(a1,min(u[a][j]+m1,u[b][j]+n1));
				a2 = max(a2,min(u[a][j]+m2,u[b][j]+n2));
			}
			if(a1<a2)ri = m2;
			else le = m1; 
		}
		ans = min(ans,(int)round(a1*2.0));
		nx = m1;
		le = 0.0, ri = nx;
		rep(k,1,30){
			m1 = (le+le+ri)/3.0, n1 = e[i].fi - m1;
			m2 = (le+ri+ri)/3.0, n2 = e[i].fi - m2;
			a1 = a2 = 0.0;
			rep(j,1,n){
				a1 = max(a1,min(u[a][j]+m1,u[b][j]+n1));
				a2 = max(a2,min(u[a][j]+m2,u[b][j]+n2));
			}
			if(a1<a2)ri = m2;
			else le = m1; 
		}
		ans = min(ans,(int)round(a1*2.0));
		le = nx, ri = e[i].fi;
		rep(k,1,30){
			m1 = (le+le+ri)/3.0, n1 = e[i].fi - m1;
			m2 = (le+ri+ri)/3.0, n2 = e[i].fi - m2;
			a1 = a2 = 0.0;
			rep(j,1,n){
				a1 = max(a1,min(u[a][j]+m1,u[b][j]+n1));
				a2 = max(a2,min(u[a][j]+m2,u[b][j]+n2));
			}
			if(a1<a2)ri = m2;
			else le = m1; 
		}
		ans = min(ans,(int)round(a1*2.0));
	}
	if(ans&1)cout<<ans/2<<".5\n";
	else cout<<ans/2<<".0\n";
    return 0;
}