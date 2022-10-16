#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define asd(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 1000000009;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,id,pos;
ll a,b,c,d,ans;
plll x[MAX];
vector<ll> st[MAX],en[MAX];
map<plll,int> hs;

inline void norm(ll &a,ll &b,ll &c){//Normalisasi persamaan garis
	if(a<0 || !a && b<0)a*= -1, b*=-1, c*= -1;
	d = abs(__gcd(a,__gcd(b,c)));
	a/= d, b/= d, c/= d;
}

inline bool intersect(pll &a,pll &b,ll &r){
	return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se) <= r*r*4;
}

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll x1,y1,x2,y2;
	//Semua koordinat dikali 2 sehingga titik tengah antara 2 lingkaran merupakan integer
	cin>>n>>m;
	//persamaan garis lurus = Ax + By + C = 0
	//(y - y1)/(y2 - y1) = (x - x1)/(x2 - x1)
	//A = y1-y2, B = x2-x1, C = y1(x1 - x2) + x1(y2 - y1)
	rep(i,1,n){
		cin>>x1>>y1>>x2>>y2;
		x1<<=1, x2<<=1, y1<<=1, y2<<=1;
		a = y1-y2, b = x2-x1, c = -y1*b - x1*a;
		norm(a,b,c);
		if(!hs.count({a,{b,c}}))pos = hs[{a,{b,c}}] = ++id;
		else pos = hs[{a,{b,c}}];
		
		if(!b)x1 = y1, x2 = y2;
		if(x1>x2)swap(x1,x2);
		st[pos].pb(x1), en[pos].pb(x2);
	}
	rep(i,1,m){
		cin>>x[i].sf>>x[i].ss>>x[i].fi;
		x[i].sf<<=1, x[i].ss<<=1, x[i].fi<<=1;
	}
	rep(i,1,id)sort(all(en[i])), sort(all(st[i]));
	rep(i,1,m)rep(j,i+1,m)if(x[i].fi==x[j].fi && !intersect(x[i].se,x[j].se,x[i].fi)){
		x1 = x[i].sf, x2 = x[j].sf;
		y1 = x[i].ss, y2 = x[j].ss;
		a = y1-y2, b = x2-x1;
		//persamaan garis yang tegak lurus dari Ax + By + C = 0 adalah Bx - Ay = 0
		swap(a,b), b = -b;
		x1 = (x1+x2)/2, y1 = (y1+y2)/2;
		//cari nilai C
		c = -a*x1 - b*y1;
		norm(a,b,c);
		if(!hs.count({a,{b,c}}))continue;
		pos = hs[{a,{b,c}}];
		a = b ? x1 : y1;
		//cara hitung segmen yang termasuk itu pake eksklusi dari semua segmen di garis tersebut
		ans+= 	(upper_bound(all(st[pos]),a) - st[pos].begin()) - 
				(lower_bound(all(en[pos]),a) - en[pos].begin());
	}
	cout<<ans<<endl;
	return 0;
}