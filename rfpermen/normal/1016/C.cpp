#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MAX =3e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,m,x[2][MAX],y[2][2][MAX],z[2][2][MAX],ans,nw,id;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,0,1)rep(j,1,n)cin>>x[i][j],y[i][1][j] = y[i][1][j-1]+x[i][j];
    rep(i,0,1)rap(j,n,1)z[i][1][j] = z[i][1][j+1]+x[i][j], z[i][0][j] = z[i][0][j+1]+(n-j)*x[i][j], y[i][0][j] = y[i][0][j+1]+z[i][1][j+1];
    ans = y[0][0][1] + z[1][0][1] + n*z[1][1][1];
    rep(i,1,n){
    	if(i&1){
    		ans = max(ans,nw+y[0][0][i]+id*z[0][1][i]+z[1][0][i]+(id+n-i+1)*z[1][1][i]);
    		nw+=x[0][i]*(id++);
    		ans = max(ans,nw+y[1][0][i]+id*z[1][1][i]+z[0][0][i+1]+(id+n-i+1)*z[0][1][i+1]);
    		nw+=x[1][i]*(id++);
		}
		else {
    		ans = max(ans,nw+y[1][0][i]+id*z[1][1][i]+z[0][0][i]+(id+n-i+1)*z[0][1][i]);
    		nw+=x[1][i]*(id++);
    		ans = max(ans,nw+y[0][0][i]+id*z[0][1][i]+z[1][0][i+1]+(id+n-i+1)*z[1][1][i+1]);
    		nw+=x[0][i]*(id++);
		}
	}
    cout<<ans<<endl;
	return 0;
}