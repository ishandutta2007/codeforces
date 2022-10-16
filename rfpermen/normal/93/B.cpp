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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const int MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

int n,id,us;
double v,w,m,nw,rem,z;
vector<pair<int,double>> ans[55];

int main(){
	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>w>>m;
    v = n*w/m;
    id = 1, nw = w;
    rep(i,1,m){
    	rem = v;
    	while(rem>1e-6){
    		z = min(rem,nw);
    		++us;
    		if(us>2)return cout<<"NO\n",0;
    		ans[i].pb({id,z});
    		rem-=z;
    		nw-=z;
    		if(nw<=1e-6)++id, nw = w, us = 0;
		}
	}
	cout<<"YES\n";
	rep(i,1,m){
		for(auto j:ans[i])cout<<j.fi<<' '<<j.se<<' ';
		cout<<endl;
	}
    return 0;
}