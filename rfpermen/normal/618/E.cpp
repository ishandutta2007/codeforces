#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,q,ag[MAX],lz[MAX],len[MAX],ty,a,b,c,st,res,bt;
double si[365],co[365],x[MAX],y[MAX],dx,dy,nx,ny;

int main(){
	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,359)si[i] = sin(-i*pi/180.0), co[i] = cos(-i*pi/180.0);
//    rep(i,0,359)cout<<co[i]<<' '<<si[i]<<endl;
	
    cin>>n>>q;
    --n;
    //semua data yg disimpen itu titik merah/start
    rep(i,0,n)len[i] = 1;
    m = n/block;
    rep(i,0,m)x[i] = i*block;
    while(q--){
    	cin>>ty>>a>>b;
    	--a;
    	if(ty==1){
    		//disini kita mau cari sudut di titik a
    		//+ kita mau update sudut segment a
    		//dan juga update semua coor titik didepan a
    		
			st = a/block;
    		res = (lz[st]+ag[a])%360;
    		dx = co[res]*b, dy = si[res]*b;
    		rep(i,st+1,m)x[i]+= dx, y[i]+= dy;
    		len[a]+= b;
		}
		else {
			//cari coor titik a
			//update semua sudut lazy dan dalem lazy nya a
			//dan juga update semua coor titik didepan a
			
			st = a/block;
    		bt = min((st+1)*block,n+1)-1;
    		dx = x[st], dy = y[st];
    		
    		for(int i = st*block; i<a; ++i){
    			res = (lz[st]+ag[i])%360;
    			dx+= len[i]*co[res], dy+= len[i]*si[res];
			}
//			cout<<">> "<<dx<<' '<<dy<<endl;
			
			rep(i,a,bt)ag[i]+= b;
			rep(i,st+1,m){
				lz[i]+= b;
				nx = co[b]*(x[i]-dx) - si[b]*(y[i]-dy) + dx;
				ny = si[b]*(x[i]-dx) + co[b]*(y[i]-dy) + dy;
//				cout<<co[b]<<' '<<si[b]<<endl;
//				cout<<i<<" = "<<x[i]<<' '<<y[i]<<endl;
//				cout<<i<<" = "<<nx<<' '<<ny<<endl;
				x[i] = nx, y[i] = ny;
			}
		}
		st = n/block;
		dx = x[st], dy = y[st];
//		cout<<dx<<' '<<dy<<endl;
		
		for(int i = st*block; i<=n; ++i){
			res = (lz[st]+ag[i])%360;
			dx+= len[i]*co[res], dy+= len[i]*si[res];
		}
		cout<<dx<<' '<<dy<<endl;
	}
	return 0;
}