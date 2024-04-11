#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,a,b,k,cnt[MAX],nw,dp[MAX];
bool vis[MAX];
set<int> s;
vector<int> v[MAX];
vector<ari(3)> z;
PQr(pii) q;

int f(int nw){
	if(dp[nw]!=-1)return dp[nw];
	int ret = 0;
	for(int i:v[nw])ret = max(ret,f(i)+1);
	return dp[nw] = ret;
}

void bt(int nw){
	vis[nw] = 1;
	for(int i:v[nw])if(dp[nw]==f(i)+1){
		bt(i);
		break;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>k>>a>>b;
		z.pb({a,b,k});
	}
	sort(all(z));
	auto it = s.begin();
	for(ari(3) i:z){
		a = i[0], b = i[1], k = i[2];
		while(!q.empty() && q.top().fi<a){
			nw = q.top().se, q.pop();
			--cnt[nw];
			if(!cnt[nw]){
				it = s.find(nw);
				if(it!=s.begin()){
					--it;
					v[*it].pb(nw);
					++it;
				}
				++it;
				if(it!=s.end())v[nw].pb(*it);
				s.erase(nw);
			}
		}
		if(!cnt[k])s.insert(k);
		++cnt[k], q.push({b,k});
	}
	nw = 0;
	for(int i:s){
//		db(i);
		if(nw)v[nw].pb(i);
		nw = i;
	}
//	rep(i,1,n){
//		cout<<i<<" = ";
//		for(int j:v[i])cout<<j<<" "; cout<<endl;
//	}
	mems(dp,-1);
	int ans = 0;
	rep(i,1,n)ans = max(ans,f(i));
	cout<<n - (ans+1)<<endl;
	rep(i,1,n)if(ans==f(i)){
		bt(i);
		break;
	}
	rep(i,1,n)if(!vis[i])cout<<i<<" "; cout<<endl;
	return 0;
}