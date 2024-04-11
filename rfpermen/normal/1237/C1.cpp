#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,a[MAX],b[MAX],c[MAX],idx,idy;
set<piii> x[MAX];
vector<int> y[MAX],tmp,ans;
map<int,int> hsx, hsy;

bool cmp(int aa,int bb){
	return a[aa] < a[bb];
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>a[i]>>b[i]>>c[i];
    	if(!hsx.count(a[i]))hsx[a[i]] = ++idx;
    	x[hsx[a[i]]].insert({b[i],{c[i],i}});
	}
	rep(i,1,idx){
		hsy.clear(), idy = 0;
		for(auto j:x[i]){
			if(!hsy.count(j.fi)){
				hsy[j.fi] = ++idy;
				assert(y[idy].empty());
			}
			y[hsy[j.fi]].pb(j.ss);
		}
		rep(j,1,idy){
			while(y[j].size()>1){
				cout<<y[j].back()<<' ';
				y[j].pob();
				cout<<y[j].back()<<'\n';
				y[j].pob();
			}
			if(!y[j].empty())tmp.pb(y[j][0]), y[j].pob();
		}
		while(tmp.size()>1){
			cout<<tmp.back()<<' ';
			tmp.pob();
			cout<<tmp.back()<<'\n';
			tmp.pob();
		}
		
		if(!tmp.empty())ans.pb(tmp[0]), tmp.pob();
	}
	sort(all(ans),cmp);
	while(!ans.empty()){
		cout<<ans.back()<<' ';
		ans.pob();
		cout<<ans.back()<<'\n';
		ans.pob();
	}
    return 0;
}