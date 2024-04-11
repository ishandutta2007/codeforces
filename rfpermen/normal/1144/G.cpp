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
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,z[MAX],a,b,opt,na,nb,id;
pii x,y,tmp;
vector<pii> v;
vector<int> ans;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>z[i];
    x = y = {-MOD,MOD};
    //x = itu terakhir ambil pake inc
    //y = itu terakhir ambil pake dec
    v.pb({0,0});
    rep(i,1,n){
    	na = nb = -1;
    	//pake x
    	opt = -1;
    	if(a!=-1&&x.fi<z[i])opt = x.se, na = a;
    	if(b!=-1&&y.fi<z[i]&&y.se>opt)opt = y.se, na = b;
    	tmp = {z[i],opt};
    	
    	//pake y
    	opt = MOD;
    	if(a!=-1&&x.se>z[i])opt = x.fi, nb = a;
    	if(b!=-1&&y.se>z[i]&&y.fi<opt)opt = y.fi, nb = b;
    	x = tmp, y = {opt,z[i]};
    	
    	if(na==-1&&nb==-1)return cout<<"NO\n",0;
    	
    	if(na!=-1)v.pb({0,na}), a = ++id;
    	else a = -1;
    	
    	if(nb!=-1)v.pb({1,nb}), b = ++id;
    	else b = -1;
	}
	if(a==-1)a = b;
	while(a!=0)ans.pb(v[a].fi), a = v[a].se;
	cout<<"YES\n";
	reverse(all(ans));
	for(auto i:ans)cout<<i<<' '; cout<<endl;
    return 0;
}