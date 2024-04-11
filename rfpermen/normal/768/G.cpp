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
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
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
#define popcount __builtin_popcountll
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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,a,b,rt,sz[MAX],ans[MAX],val;
vi v[MAX];
map<int,int> cnt;
set<int> s;

void dfs(int nw){
	sz[nw] = 1;
	for(int i:v[nw]){
		dfs(i);
		sz[nw]+= sz[i];
	}
	return;
}

void add(int nw){
	++cnt[sz[nw]];
	for(int i:v[nw])add(i);
	return;
}
void del(int nw){
	--cnt[sz[nw]];
	if(!cnt[sz[nw]])cnt.erase(sz[nw]);
	for(int i:v[nw])del(i);
	return;
}

void solve(int nw,int sm){
	if(v[nw].empty()){
		++cnt[1];
		return;
	}
	int at = n-sz[nw];
	int mn = MOD, big = 0;
	for(int i:v[nw]){
		if(sz[big]<sz[i])big = i;
		mn = min(mn,sz[i]);
	}
	if(at>sz[big]){
		ans[nw] = at;
		int mid = at+mn>>1;
		auto it = cnt.lower_bound(at-mid);
		if(it!=cnt.end()){
			ans[nw] = min(ans[nw],max(mn+(*it).fi,at-(*it).fi));
		}
		if(it!=cnt.begin()){
			--it;
			ans[nw] = min(ans[nw],max(mn+(*it).fi,at-(*it).fi));
		}
		
		auto it2 = s.lower_bound(at-mid-sm);
		if(it2!=s.end()){
			val = (*it2)+sm;
			ans[nw] = min(ans[nw],max(mn+val,at-val));
		}
		if(it2!=s.begin()){
			--it2;
			val = (*it2)+sm;
			ans[nw] = min(ans[nw],max(mn+val,at-val));
		}
		ans[nw] = max(ans[nw],sz[big]);
	}
	else ans[nw] = sz[big];
	s.insert(-sm);
	for(int i:v[nw])if(i!=big)add(i);
	solve(big,sm+sz[nw]-sz[big]);
	for(int i:v[nw])if(i!=big){
		del(i);
		solve(i,sm+sz[nw]-sz[i]);
	}
	s.erase(-sm);
	++cnt[sz[nw]];
	return;
}

void add2(int nw){
	s.insert(sz[nw]);
	for(int i:v[nw])add2(i);
	return;
}

void f(int nw){
	if(v[nw].empty()){
		s.insert(1);
		return;
	}
	int big = 0, nd = 0, at = n-sz[nw], mn = MOD;
	for(int i:v[nw]){
		if(sz[big]<sz[i])nd = big, big = i;
		else if(sz[nd]<sz[i])nd = i;
		mn = min(mn,sz[i]);
	}
	for(int i:v[nw])if(i!=big){
		f(i);
		s.clear();
	}
	f(big);
	if(at)mn = min(mn,at);
	
	if(sz[big]>at){
		ans[nw] = sz[big];
		int mid = sz[big]+mn>>1;
		auto it = s.lower_bound(sz[big]-mid);
		
		if(it!=s.end()){
			val = (*it);
			ans[nw] = min(ans[nw],max(mn+val,sz[big]-val));
		}
		if(it!=s.begin()){
			--it;
			val = (*it);
			ans[nw] = min(ans[nw],max(mn+val,sz[big]-val));
		}
		ans[nw] = max(ans[nw],max(at,sz[nd]));
	}
	for(int i:v[nw])if(i!=big)add2(i);
	s.insert(sz[nw]);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>a>>b;
		if(!a)rt = b;
		else v[a].pb(b);
		ans[i] = n-1;
	}
	dfs(rt);
	for(int i:v[rt])add(i);
	for(int i:v[rt]){
		del(i);
		solve(i,0);
	}
	f(rt);
	rep(i,1,n)cout<<ans[i]<<endl;
	return 0;
}