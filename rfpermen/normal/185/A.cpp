#include <bits/stdc++.h>

#pragma GCC optimize("Os")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll n,x[2][2],y[2][2],z[2][2];

ll f(ll pw){
	if(pw<0)return 1;
	x[0][0] = x[1][1] = 3;
	x[0][1] = x[1][0] = 1;
	rep(i,0,1)rep(j,0,1)y[i][j] = x[i][j];
	while(pw){
		if(pw&1){
			rep(i,0,1)rep(j,0,1)z[i][j] = 0;
			rep(i,0,1)rep(j,0,1)rep(k,0,1)z[i][j]+=x[i][k]*y[k][j];
			rep(i,0,1)rep(j,0,1)x[i][j] = z[i][j]%MOD;
		}
		rep(i,0,1)rep(j,0,1)z[i][j] = 0;
		rep(i,0,1)rep(j,0,1)rep(k,0,1)z[i][j]+=y[i][k]*y[k][j];
		rep(i,0,1)rep(j,0,1)y[i][j] = z[i][j]%MOD;
		pw>>=1;
	}
//	rep(i,0,1){
//		rep(j,0,1)cout<<x[i][j]<<' '; cout<<'\n';
//	}
	return x[0][0];
}

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<f(n-1)<<endl;
    return 0;
}