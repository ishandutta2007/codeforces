#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 6e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,k,a,b,c,d,cs,ans,tmp,tgt,x[MAX],y[MAX],ix,iy,id,ls;
vector<plll> v[MAX];

ll dfs(int nw,int par){
	ll lf = 0;
	for(plll i:v[nw])if(i.fi!=par){
		tmp = dfs(i.fi,nw);
		cs+= i.sf*tmp;
		if(i.ss==1){
			while(i.sf)x[++ix] = (i.sf+1>>1)*tmp, i.sf>>=1;
		}
		else {
			while(i.sf)y[++iy] = (i.sf+1>>1)*tmp, i.sf>>=1;
		}
		lf+= tmp;
	}
	if(!lf)lf = 1;
	return lf;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>k;
    	rep(i,1,n)v[i].clear();
    	rep(i,2,n){
    		cin>>a>>b>>c>>d;
    		v[a].pb({b,{c,d}}), v[b].pb({a,{c,d}});
		}
		ans = cs = 0;
		ix = iy = 0;
		x[ix+1] = 0;
		dfs(1,0);
		if(iy>6e6||ix>6e6)return 1;
		sort(x+1,x+1+ix);
		reverse(x+1,x+1+ix);
		sort(y+1,y+1+iy);
		reverse(y+1,y+1+iy);
		
		if(cs>k){
			tgt = cs-k;
			id = 1;
			rep(i,1,iy)tgt-= y[i];
			ans = MOD;
			rap(i,iy,0){
				while(tgt>0 && id<=ix)tgt-= x[id], ++id;
				if(tgt>0)break;
				ans = min(ans,(ll)i*2+id-1);
				tgt+= y[i];
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}