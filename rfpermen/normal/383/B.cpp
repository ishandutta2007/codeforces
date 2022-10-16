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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,r,c,a,b,p[MAX],mask[MAX],nr,nc;
map<pii,int> hs,as;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>a>>b;
    	p[i] = i;
    	if(a==1)mask[i] = 1;
    	if(a==n)mask[i]|= 2;
    	if(b==1)mask[i]|= 4;
    	if(b==n)mask[i]|= 8;
    	hs[{a,b}] = i;
    	as[{b,a}] = i;
	}
	for(auto i:hs){
		r = i.ff, c = i.fs;
		a = par(i.se);
		rep(k,0,7){
			nr = r+dr[k], nc = c+dc[k];
//			cout<<">> "<<r<<' '<<c<<' '<<nr<<' '<<nc<<endl;
			if(!hs.count({nr,nc}))continue;
//			cout<<"IN\n";
			b = par(hs[{nr,nc}]);
			if(a==b)continue;
			p[b] = a;
			mask[a]|=mask[b];
		}
	}
//	rep(i,1,m)cout<<mask[i]<<' '; cout<<endl;
	auto it = hs.begin();
	for(auto i:hs){
		a = par(i.se);
		it = hs.lower_bound({i.ff+1,i.fs});
		if(it!=hs.end() && (*it).ff==i.ff+1){
			b = par((*it).se);
			mask[b]|=(mask[a]&9);
			mask[a]|=(mask[b]&6);
		}
		it = as.lower_bound({i.fs+1,i.ff});
		if(it!=as.end() && (*it).ff==i.fs+1){
//			cout<<">> "<<i.ff<<' '<<i.fs<<endl;
			b = par((*it).se);
			mask[b]|=(mask[a]&6);
			mask[a]|=(mask[b]&9);
		}
	}
	rep(i,1,m)if((mask[i]&3)==3||(mask[i]&5)==5||(mask[i]&10)==10||(mask[i]&12)==12)return cout<<"-1\n",0;
	cout<<n+n-2<<endl;
    return 0;
}