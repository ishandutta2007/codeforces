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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 3e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,x,y[4],cnt,k,mx;
bool z,st[16];

void f(int nw,int mask){
	cnt = 0;
	memset(y,0,sizeof y);
	rap(i,nw-1,0){
		if(mask&(1<<i)){
			++cnt;
			rep(j,0,k)if(i&(1<<j))++y[j];
		}
	}
	if(cnt)rep(j,0,k){
		if((y[j]<<1)>cnt)break;
		if(j==k){
			cout<<"YES\n";
			exit(0);
		}
	}
	if(nw==mx)return;
	if(st[nw])f(nw+1,mask|(1<<nw));
	f(nw+1,mask);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    mx = 1<<k;
    --k;
    rep(i,1,n){
    	x = 0;
    	rep(j,0,k)cin>>z, x|=z<<j;
    	st[x] = 1;
	}
	f(0,0);
	cout<<"NO\n";
	return 0;
}