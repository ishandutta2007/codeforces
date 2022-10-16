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
const int MAX = 400+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

int n,m,r[MAX][MAX],c[MAX][MAX],a,b,d,ans,g;
bool x[MAX][MAX];
char z;

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(x,1,sizeof x);
    rep(i,1,n)rep(j,1,m){
    	cin>>z;
    	x[i][j] = a = (z=='1');
    	r[i][j] = r[i-1][j]+a;
    	c[i][j] = c[i][j-1]+a;
	}
    rep(i,1,n)rep(j,1,m){
    	if(x[i][j])continue;
    	a = i, b = j;
    	while(!x[a+1][b+1]){
    		g+=2;
    		++a, ++b;
    		if(r[a][j] - r[i-1][j]==0 && c[a][b] - c[a][j-1]==0)++ans;
    		if(r[a][b] - r[i-1][b]==0 && c[i][b] - c[i][j-1]==0)++ans;
		}
		a = i, b = j;
		while(!x[a+1][b-1]){
    		g+=2;
    		++a, --b;
    		if(r[a][j] - r[i-1][j]==0 && c[a][j] - c[a][b-1]==0)++ans;
    		if(r[a][b] - r[i-1][b]==0 && c[i][j] - c[i][b-1]==0)++ans;
		}
		a = i, b = d = j;
		while(!x[a+1][b+1]&&!x[a+1][d-1]){
    		++g;
			++a, ++b, --d;
			if(c[a][b] - c[a][d-1]==0)++ans;
		}
		a = i, b = d = j;
		while(!x[a-1][b+1]&&!x[a-1][d-1]){
    		++g;
			--a, ++b, --d;
			if(c[a][b] - c[a][d-1]==0)++ans;
		}
		a = d = i, b = j;
		while(!x[a+1][b+1]&&!x[d-1][b+1]){
    		++g;
			++a, ++b, --d;
			if(r[a][b] - r[d-1][b]==0)++ans;
		}
		a = d = i, b = j;
		while(!x[a+1][b-1]&&!x[d-1][b-1]){
    		++g;
			++a, --b, --d;
			if(r[a][b] - r[d-1][b]==0)++ans;
		}
	}
//	db(g);
	cout<<ans<<endl;
    return 0;
}