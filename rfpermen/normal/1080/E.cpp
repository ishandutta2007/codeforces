#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
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
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,m,x[255][255],cnt[26],hit,sf,gs,id,lps[505],sz;
ll ans;
bitset<208> z[31380][251],nw;
vector<bitset<208>> v;
char c;

int l,r;
inline void solve(){
	sz = v.size()<<1;
	rep(i,0,sz)lps[i] = 0;
	lps[0] = 0; lps[1] = 1;
	int j,k;
	rep(i,2,sz){
	    l = (i>>1) - (lps[i]>>1);
	    r = ((i-1)>>1) + (lps[i]>>1);
	    while(1){ // widen
	        if(l == 0 || r+1 == v.size())break;
	        if(v[l-1] != v[r+1])break;
	        l--, r++;
	    }
	    lps[i] = r - l + 1;
	    // jump
	    if(lps[i] > 2){
	        j = i-1, k = i+1; // while lps[j] inside lps[i]
	        while(lps[j] - j < lps[i] - i) lps[k++] = lps[j--];
	        lps[k] = lps[i] - (i - j); // set lps[k] to edge of lps[i]
	        i = k-1; // jump to mirror, which is k
	    }
	}
	rep(i,1,sz)ans+= (lps[i]+1)>>1;
	v.clear();
	return;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>c, x[i][j] = c-'a';
    rep(i,1,n){
    	id = 0;
    	rep(a,1,m){
    		mems(cnt,0);
    		hit = 0, nw = 0;
    		rep(b,a,m){
    			++id;
    			sf = x[i][b];
    			if(cnt[sf]&1)--hit;
    			else ++hit;
    			++cnt[sf];
    			gs = sf<<3;
    			rep(k,0,7)nw[gs+k] = (cnt[sf]&(1<<k))>0;
    			if(hit<2)z[id][i] = nw;
			}
		}
	}
	++n;
	rep(k,1,id){
		v.clear();		
		rep(i,1,n){
			if(z[k][i]==0){
				if(!v.empty())solve();
			}
			else v.pb(z[k][i]);
		}
	}
	cout<<ans<<endl;
    return 0;
}