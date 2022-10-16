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
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2500+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,q,ty,val,ls;
ll bit[MAX][MAX],ret;
map<piiii,ll> hs;

inline void upd(int i,int x){
	for(; i<=n; i+=(i&-i)){
		for(int j = x; j<=m; j+=(j&-j))bit[i][j]+=val;
	}
	return;
}

inline ll que(int i,int x){
	ret = 0;
	for(; i>0; i-=(i&-i)){
		for(int j = x; j>0; j-=(j&-j))ret+= bit[i][j];
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    int x1,y1,x2,y2;
    cin>>n>>m>>q;
    ls = 1;
    while(q--){
    	cin>>ty>>x1>>y1>>x2>>y2;
    	if(ty==1){
	    	val = ls;
	    	ls*=3;
	    	hs[{{x1,y1},{x2,y2}}] = val;
	    	upd(x1,y1);
	    	upd(x2+1,y2+1);
	    	val = -val;
	    	upd(x2+1,y1);
	    	upd(x1,y2+1);
		}
    	else if(ty==2){
    		val = hs[{{x1,y1},{x2,y2}}];
    		hs.erase({{x1,y1},{x2,y2}});
	    	upd(x2+1,y1);
	    	upd(x1,y2+1);
	    	val = -val;
	    	upd(x1,y1);
	    	upd(x2+1,y2+1);
		}
		else cout<<(que(x1,y1)==que(x2,y2) ? "Yes" : "No")<<endl;
	}
    return 0;
}