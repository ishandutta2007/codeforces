#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;

int n,m;
bool x[55][55];
ll cnt,ans,pw[55];

int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	rep(i,1,50)pw[i] = pw[i-1]*2;
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>x[i][j];
	rep(i,1,n){
		cnt = 0;
		rep(j,1,m)cnt+=x[i][j];
		ans+= pw[cnt]+pw[m-cnt]-2;
	}
	rep(j,1,m){
		cnt = 0;
		rep(i,1,n)cnt+=x[i][j];
		ans+= pw[cnt]+pw[n-cnt]-2;
	}
	cout<<ans-n*m<<endl;
	return 0;
}