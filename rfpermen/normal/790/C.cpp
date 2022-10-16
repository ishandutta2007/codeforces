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
const int MAX = 1e3+5;
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

int n,dp[76][76][76][2],ans;
string s;
vector<int> po,pv,pk;

int f(int nw,int v,int k,int o,bool ls){
	if(nw>n)return 0;
	int &ret = dp[v][k][o][ls];
	if(ret!=-1)return ret;
	int pos, id;
	ret = MOD;
	if(v!=pv.size()){
		pos = pv[v];
		id = upper_bound(all(pk),pv[v]) - pk.begin();
		if(id<k)pos+= k-id;
		id = upper_bound(all(po),pv[v]) - po.begin();
		if(id<o)pos+= o-id;
		ret = min(ret,f(nw+1,v+1,k,o,1) + pos-nw);
	}
	if(k!=pk.size() && !ls){
		pos = pk[k];
		id = upper_bound(all(pv),pk[k]) - pv.begin();
		if(id<v)pos+= v-id;
		id = upper_bound(all(po),pk[k]) - po.begin();
		if(id<o)pos+= o-id;
		ret = min(ret,f(nw+1,v,k+1,o,0) + pos-nw);
	}
	if(o!=po.size()){
		pos = po[o];
		id = upper_bound(all(pv),po[o]) - pv.begin();
		if(id<v)pos+= v-id;
		id = upper_bound(all(pk),po[o]) - pk.begin();
		if(id<k)pos+= k-id;
		ret = min(ret,f(nw+1,v,k,o+1,0) + pos-nw);
	}
	return ret;
}

void bt(int nw,int v,int k,int o,bool ls){
	if(nw>n)return;
	int ret = dp[v][k][o][ls];
	if(v!=pv.size()){
		if(ret == f(nw+1,v+1,k,o,1) + abs(nw-pv[v])){
			cout<<"V";
			bt(nw+1,v+1,k,o,1);
			return;
		}
	}
	if(k!=pk.size() && !ls){
		if(ret == f(nw+1,v,k+1,o,0) + abs(nw-pk[k])){
			cout<<"K";
			bt(nw+1,v,k+1,o,0);
			return;
		}
	}
	if(o!=po.size()){
		if(ret == f(nw+1,v,k,o+1,0) + abs(nw-po[o])){
			cout<<"O";
			bt(nw+1,v,k,o+1,0);
			return;
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s>>s;
	n = s.size();
	s = '0'+s;
	mems(dp,-1);
	rep(i,1,n){
		if(s[i]=='V')pv.pb(i);
		else if(s[i]=='K')pk.pb(i);
		else po.pb(i);
	}
//	ou3(pv.size(),pk.size(),po.size());
	cout<<f(1,0,0,0,0)<<endl;
//	bt(1,0,0,0,0);
	return 0;
}