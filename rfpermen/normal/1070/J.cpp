#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,N) for(int i = n; i<=N; i++)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define endl '\n'
const int MAX = 1e5+5;
const int MOD = 1000000000+7;

int n,m,k,tc,ans,z[26],dp[26][30005],res;
char c;

int f(int nw,int rem){
//	cout<<nw<<" "<<rem<<endl;cout<<"LALAL = "<<m-k+z[nw]+rem<<endl, 
	if(rem==n)return 0;
	if(nw==26)return 1e9;
	if(dp[nw][rem]!=-1)return dp[nw][rem];
	if(z[nw]+rem<=n)return dp[nw][rem] = min(f(nw+1,rem),f(nw+1,rem+z[nw]));
	if(k-z[nw]-rem<m)return dp[nw][rem] = min((n-rem)*(m-k+z[nw]+rem),f(nw+1,rem));
	return dp[nw][rem] = 0;
}

int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	while(tc--){
		cin>>n>>m>>k;
		if(n>m)swap(n,m);
		memset(z,0,sizeof z);
		rep(i,1,k)cin>>c, z[c-'A']++;
		rep(i,0,25)rep(j,0,n)dp[i][j] = -1;
		sort(z,z+26); reverse(z,z+26);
		res = f(0,0);
		rep(ii,1,200){
			if(!res)break;
			rep(i,0,25)rep(j,0,n)dp[i][j] = -1;
			random_shuffle(z,z+26);
			res = min(res,f(0,0));
		}
		cout<<res<<endl;
	}
	return 0;
}