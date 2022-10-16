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
const int MAX = 1e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n;
string s[MAX];
map<ari(2),int> nx;
map<ari(3),int> dp;

void dnc(int nw,int le,int ri){
	if(le==ri)return;
	if(s[le].size()==nw)++le;
	char ls = s[le][nw];
	int a = le;
	rep(i,le,ri){
		if(s[i][nw]!=ls)nx[{nw,a}] = i-1, dnc(nw+1,a,i-1), ls = s[i][nw], a = i;
	}
	nx[{nw,a}] = ri;
	dnc(nw+1,a,ri);
	return;
}

int f(int nw,int le,int ri,int cnt){
//	cout<<"<> "<<nw<<" "<<le<<" "<<ri<<" "<<cnt<<endl;
	if(ri-le+1<=cnt)return 0;
	if(le==ri)return nw+1;
	if(dp.count({nw,le,cnt}))return dp[{nw,le,cnt}];
	int &ret = dp[{nw,le,cnt}];
	if(s[le].size()==nw)return ret = f(nw,le+1,ri,cnt-1);
	int rx = nx[{nw,le}];
//	ou3(nw,le,rx);
	if(ri==rx)return ret = f(nw+1,le,ri,cnt+1) + nw+1;
	ret = MOD;
	for(int i = 0; i<=rx-le && i<=cnt; ++i)ret = min(ret,f(nw+1,le,rx,i+1) + f(nw,rx+1,ri,cnt-i) + nw+1);
	if(cnt>=rx-le+1)ret = min(ret, f(nw,rx+1,ri,cnt-(rx-le+1)));
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>s[i];
    sort(s+1,s+1+n);
//    rep(i,1,n)cout<<s[i]<<endl;
    dnc(0,1,n);
//    for(auto i:nx)cout<<i.fi[0]<<" "<<i.fi[1]<<" "<<i.se<<endl;
    cout<<f(0,1,n,0)<<endl;
//    for(auto i:dp){
//    	rep(j,0,3)cout<<i.fi[j]<<" "; cout<<"= "<<i.se<<endl;
//	}
//	db(f(2,2,2,0));
	return 0;
}