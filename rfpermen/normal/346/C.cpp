#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
//#define size(n) ((int)(n).size())
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,x,a,b,mx[MAX],bit[MAX],res,y[MAX],nw;
set<int> s;

inline void upd(int i,int val){
	for(;i<=a;i+=i&-i)bit[i] = min(bit[i],val);
	return;
}
int ret;
inline int que(int i){
	ret = MOD;
	for(;i>0;i-=i&-i)ret = min(bit[i],ret);
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x;
		if(x!=2)s.insert(x);
	}
    cin>>a>>b;
    for(int i:s){
    	nw = (b+i-1)/i*i;
    	while(nw<a){
    		mx[nw-b] = i;
    		nw+= i;
		}
	}
	a-= b;
	asd(i,1,a)bit[i] = y[i] = MOD;
	rap(i,a-1,0){
		if(!mx[i])y[i] = y[i+1]+1;
		else y[i] = que(min(i+mx[i]-1,a))+1;
		if(i)upd(i,y[i]);
	}
	cout<<y[0]<<endl;
    return 0;
}