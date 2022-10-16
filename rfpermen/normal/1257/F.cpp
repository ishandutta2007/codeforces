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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

struct tr{
	int nx[16];
	int xo;
}z[(1<<15)*100];

int n,x[MAX],cnt[MAX],id;

inline void ins(int pt){
	int nw = 0;
	rep(i,1,n){
		if(!z[nw].nx[cnt[i]])z[nw].nx[cnt[i]] = ++id;
		nw = z[nw].nx[cnt[i]];
	}
	z[nw].xo = pt;
	return;
}

void bf(int k,int pt){
	if(k==15){
		ins(pt);
		return;
	}
	rep(i,1,n)if(x[i]&(1<<k))++cnt[i];
	bf(k+1,pt);
	rep(i,1,n){
		if(x[i]&(1<<k))--cnt[i];
		else ++cnt[i];
	}
	bf(k+1,pt|(1<<k));
	rep(i,1,n)if(!(x[i]&(1<<k)))--cnt[i];
	return;
}

inline void yey(int tgt,int pt){
	int nw = 0;
	rep(i,1,n){
		if(!z[nw].nx[tgt-cnt[i]])return;
		nw = z[nw].nx[tgt-cnt[i]];
	}
	cout<<pt+z[nw].xo<<endl;
	exit(0);
}

void solve(int k,int pt){
	if(k==30){
		int mx = 0,mn = 30;
		rep(i,1,n)mx = max(cnt[i],mx), mn = min(cnt[i],mn);
		mn+=15;
		rep(i,mx,mn)yey(i,pt);
		return;
	}
	rep(i,1,n)if(x[i]&(1<<k))++cnt[i];
	solve(k+1,pt);
	rep(i,1,n){
		if(x[i]&(1<<k))--cnt[i];
		else ++cnt[i];
	}
	solve(k+1,pt|(1<<k));
	rep(i,1,n)if(!(x[i]&(1<<k)))--cnt[i];
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    bf(0,0);
    solve(15,0);
    cout<<-1;
    return 0;
}