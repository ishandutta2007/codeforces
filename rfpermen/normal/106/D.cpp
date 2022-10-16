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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,k,r[MAX][MAX],c[MAX][MAX],z[MAX*100],nx,ny,tmp;
char ty[MAX*100],x[MAX][MAX];
string ans;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>x[i][j];
    	r[i][j] = r[i-1][j], c[i][j] = c[i][j-1];
    	if(x[i][j]=='#')++r[i][j], ++c[i][j];
	}
	cin>>k;
	rep(i,1,k)cin>>ty[i]>>z[i];
	rep(a,1,n)rep(b,1,m){
		if(x[a][b]>='A' && x[a][b]<='Z'){
			nx = a, ny = b;
			st = 0;
			rep(i,1,k){
				if(ty[i]=='E'){
					tmp = ny+z[i];
					if(tmp>m || c[nx][tmp] - c[nx][ny-1])break;
					ny = tmp;
				}
				else if(ty[i]=='W'){
					tmp = ny-z[i];
					if(tmp<1 || c[nx][ny] - c[nx][tmp-1])break;
					ny = tmp;
				}
				else if(ty[i]=='N'){
					tmp = nx-z[i];
					if(tmp<1 || r[nx][ny] - r[tmp-1][ny])break;
					nx = tmp;
				}
				else {
					tmp = nx+z[i];
					if(tmp>n || r[tmp][ny] - r[nx-1][ny])break;
					nx = tmp;
				}
				if(i==k)st = 1;
			}
			if(st)ans.pb(x[a][b]);
		}
	}
	if(ans.empty())cout<<"no solution\n";
	else sort(all(ans)), cout<<ans<<endl;
    return 0;
}