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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int x[3],y[3],d[7],nw,ans,z;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    d[1] = 1, d[2] = 2, d[4] = 2, d[5] = 1;
    rep(i,0,2)cin>>x[i];
    rep(i,0,6){
    	nw = 0;
    	rep(j,0,2)y[j] = x[j];
    	rep(j,i,6){
    		if(!y[d[j]]){ans = max(ans,nw), nw = -1; break;}
    		--y[d[j]];
    		++nw;
		}
		if(nw==-1)continue;
		z = min(y[0]/3,min(y[1],y[2])/2);
		y[0]-= z*3, y[1]-= z<<1, y[2]-= z<<1;
		nw+= z*7;
    	rep(j,0,6){
    		if(!y[d[j]]){ans = max(ans,nw), nw = -1; break;}
    		--y[d[j]];
    		++nw;
		}
	}
	cout<<ans<<endl;
    return 0;
}