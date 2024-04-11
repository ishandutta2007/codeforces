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
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int k,n,m,q,mt[105][55],ig[55][55],jlh[105][55],val;
string nm[55],cp[55],s;
map<string,int> bs;
vector<pair<string,int>> ans;
bool st;
char c;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>n>>m>>q;
    rep(i,1,n)cin>>nm[i], bs[nm[i]] = i;
    rep(i,1,m){
    	cin>>cp[i];
    	cp[i].pob();
    	while(1){
    		cin>>s>>val;
    		ig[i][bs[s]]+= val;
//    		cout<<s<<' '<<val<<endl;
    		c = getchar();
    		if(c!=',')break;
		}
	}
	while(q--){
		cin>>val>>s;
		++mt[val][bs[s]];
		rep(j,1,m){
			st = 1;
			rep(o,1,n)if(ig[j][o]>mt[val][o]){
				st = 0;
				break;
			}
			if(st){
				rep(o,1,n)mt[val][o]-= ig[j][o];
				jlh[val][j]++;
				break;
			}
		}
	}
	rep(i,1,k){
		ans.clear();
		rep(j,1,m)if(jlh[i][j])ans.pb({cp[j],jlh[i][j]});
		rep(o,1,n)if(mt[i][o])ans.pb({nm[o],mt[i][o]});
		sort(all(ans));
		cout<<ans.size()<<endl;
		for(auto j:ans)cout<<j.fi<<' '<<j.se<<endl;
	}
    return 0;
}