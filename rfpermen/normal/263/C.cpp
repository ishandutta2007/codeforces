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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,a,b,ans[MAX],nw;
vector<int> v[MAX];
bool vis[MAX],fn;

inline bool cek(){
	asd(i,0,n){
		rep(k,-2,2)if(k){
			nw = i+k;
			if(nw>=n)nw-= n;
			else if(nw<0)nw+= n;
			fn = 0;
			for(int j:v[ans[i]])if(j==ans[nw]){
				fn = 1;
				break;
			}
			if(!fn)return false;
		}
	}
	return true;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n<<1){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	rep(i,1,n)if(v[i].size()!=4)return cout<<"-1\n",0;
	sort(all(v[1]));
	do{
		mems(vis,0);
		vis[1] = 1;
		ans[2] = 1, nw = 0;
		for(int i:v[1]){
			vis[i] = 1;
			ans[nw] = i;
			++nw;
			if(nw==2)++nw;
		}
		rep(i,3,n-3){
			nw = -1;
			for(int j:v[ans[i]])if(!vis[j]){
				nw = j;
				break;
			}
			if(nw==-1)break;
			ans[i+2] = nw;
			vis[nw] = 1;
		}
		if(nw!=-1 && cek()){
			asd(i,0,n)cout<<ans[i]<<' '; cout<<endl;
			return 0;
		}
	}while(next_permutation(all(v[1])));
	cout<<"-1\n";
    return 0;
}