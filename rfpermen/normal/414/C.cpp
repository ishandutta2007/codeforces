#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,k,x[MAX],a,b,q,z;
ll cnt[22][2],ans,hit;
vector<int> tmp;
bool id;

void dnc(int sz,int dep,vector<int> &v){
	if(!dep)return;
	int mid = sz>>1;
	vector<int> v1,v2;
	rep(i,0,mid)v1.pb(v[i]);
	rep(i,mid+1,sz)v2.pb(v[i]);
	dnc(mid,dep-1,v1);
	dnc(mid,dep-1,v2);
	
	v.clear();
	a = b = hit = 0;
	while(a<=mid && b<=mid){
		if(v1[a]<=v2[b])v.pb(v1[a]), ++a;
		else v.pb(v2[b]), hit+= mid-a+1, ++b;
	}
	while(a<=mid)v.pb(v1[a]), ++a;
	while(b<=mid)v.pb(v2[b]), ++b;
	cnt[dep][id]+= hit;
	if(!id)ans+= hit;
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k;
    n = 1<<k;
    rep(i,1,n)cin>>x[i], tmp.pb(x[i]);
	dnc(n-1,k,tmp);
	tmp.clear();
	rap(i,n,1)tmp.pb(x[i]);
	id = 1;
	dnc(n-1,k,tmp);
	cin>>q;
	while(q--){
		cin>>z;
		rep(i,1,z)ans+= cnt[i][1]-cnt[i][0], swap(cnt[i][1],cnt[i][0]);
		cout<<ans<<endl;
	}
    return 0;
}