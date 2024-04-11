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
 
int n,m;
bitset<200> x[205],c,inv,nul,pd;
bool UwU,r[205];

void print(){
	cout<<"YES\n";
	rep(k,0,n)cout<<r[k]; cout<<endl;
	rep(k,0,m)cout<<c[k]; cout<<endl;
	exit(0);
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m; --n,--m;
    rep(i,0,n)rep(j,0,m)cin>>UwU, x[i][j] = UwU;
    rep(j,0,m)inv[j] = 1;
    rep(i,0,n)rep(j,0,m+1){
    	//kasus yg jangan invers baris
    	r[i] = 0;
    	rep(k,0,m){
    		if(k<j)c[k] = x[i][k];
    		else c[k] = !x[i][k];
		}
		UwU = 1;
		rep(k,0,i-1){
			if(!UwU)break;
			if((x[k]^c)==nul)r[k] = 0;
			else if((x[k]^c)==inv)r[k] = 1;
			else UwU = false;
		}
		rep(k,i+1,n){
			if(!UwU)break;
			if((x[k]^c)==nul)r[k] = 1;
			else if((x[k]^c)==inv)r[k] = 0;
			else UwU = false;
		}
		if(UwU)print();
		
    	r[i] = 1;
    	rep(k,0,m){
    		if(k<j)c[k] = !x[i][k];
    		else c[k] = x[i][k];
		}
		UwU = 1;
		rep(k,0,i-1){
			if(!UwU)break;
			if((x[k]^c)==nul)r[k] = 0;
			else if((x[k]^c)==inv)r[k] = 1;
			else UwU = false;
		}
		rep(k,i+1,n){
			if(!UwU)break;
			if((x[k]^c)==nul)r[k] = 1;
			else if((x[k]^c)==inv)r[k] = 0;
			else UwU = false;
		}
		if(UwU)print();
	}
	cout<<"NO\n";
    return 0;
}