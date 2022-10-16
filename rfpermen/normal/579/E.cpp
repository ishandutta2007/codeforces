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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,-1,0,1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n;
double ans,le,ri,m1,m2,a1,a2,nw,nw2,x[MAX];

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    le = -1e4, ri = 1e4;
    rep(k,1,100){
    	m1 = (le+le+ri)/3.0;
    	m2 = (le+ri+ri)/3.0;
    	a1 = a2 = 0.0;
    	
    	nw = nw2 = 0.0;
    	rep(i,1,n){
    		nw+= x[i]-m1, nw2+= x[i]-m2;
    		if(nw<0.0)nw = 0.0;
    		if(nw2<0.0)nw2 = 0.0;
    		a1 = max(a1,nw), a2 = max(a2,nw2);
		}
		
    	nw = nw2 = 0.0;
    	rep(i,1,n){
    		nw+= x[i]-m1, nw2+= x[i]-m2;
    		if(nw>0.0)nw = 0.0;
    		if(nw2>0.0)nw2 = 0.0;
    		a1 = max(a1,-nw), a2 = max(a2,-nw2);
		}
		
		if(a1<a2)ri = m2;
		else le = m1;
	}
	cout<<a1<<endl;
    return 0;
}