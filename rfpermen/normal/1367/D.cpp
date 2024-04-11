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
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 10007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,n,x[MAX],id,cnt,hit,ada[26];
char ans[MAX];
string s;
vector<int> v;

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>s;
    	mems(ada,0);
    	for(auto i:s)++ada[i-'a'];
    	
    	id = 25;
    	cin>>n;
    	rep(i,1,n)cin>>x[i], ans[i] = 0;
    	cnt = 0;
    	while(cnt!=n){
    		rep(i,1,n)if(!ans[i]){
    			hit = 0;
    			rep(j,1,n)if(ans[j])hit+= abs(i-j);
    			if(x[i]==hit)v.pb(i);
			}
			while(ada[id]<v.size())--id;
			for(int i:v)ans[i] = id+'a';
			--id, cnt+= v.size();
			v.clear();
		}
		rep(i,1,n)cout<<ans[i]; cout<<endl;
	}
    return 0;
}