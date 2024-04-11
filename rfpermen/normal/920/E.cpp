#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,a,b,p[MAX],ans,nw;
set<int> v[MAX],rt;
vector<int> mem[MAX],er;
 
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)p[i] = i, mem[i].pb(i), rt.insert(i);
    while(m--){
    	cin>>a>>b;
    	v[a].insert(b);
    	v[b].insert(a);
	}
	rep(i,1,n){
		nw = par(i);
		for(int j:rt){
			if(j==nw || j!=par(j))continue;
			for(int k:mem[j]){
				if(!v[i].count(k)){
					a = nw, b = j;
					if(mem[a].size()<mem[b].size())nw = j, swap(a,b);
					p[b] = a;
					for(int o:mem[b])mem[a].pb(o);
					mem[b].clear();
					er.pb(b);
					break;
				}
			}
		}
		while(!er.empty())rt.erase(er.back()), er.pob();
	}
	vector<int> res;
	rep(i,1,n)if(par(i)==i)res.pb(mem[i].size());
	cout<<res.size()<<endl;
	sort(all(res));
	for(int i:res)cout<<i<<' ';
    return 0;
}