#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define rep1(i,N) for(int i=1;i<=(int)(N);i++)
#define show(x) cout<< #x<< " "<<(x)<<endl;
#define all(c) c.begin(),c.end()
#define chmax(x,y) x = max(x,y)
#define fs first
#define sc second
#define pb push_back

using namespace std;

int N,K,p;
vector<int> a,s;
int dp[20010][51];

int now[51][100];

int main(){
	cin>>N>>K>>p;
	a.resize(N);
	rep(i,N){
		cin>>a[i];
		a[i]%=p;
	}
	s.resize(N+1);
	rep(i,N) s[i+1] = (s[i] + a[i])%p;
	rep(i,N+1) rep(k,K+1) dp[i][k] = -1;
	rep(k,K+1) rep(r,p) now[k][r] = -1;
	dp[0][0] = 0;
	now[0][0] = 0;
	rep1(i,N){
		rep1(k,K){
			rep(r,p) if(now[k-1][r]>=0){
				chmax(dp[i][k],now[k-1][r]+(s[i]-r+p)%p);
			}
		}
		rep(k,K+1) if(dp[i][k]>=0) chmax(now[k][dp[i][k]%p],dp[i][k]);
	}
	cout<<dp[N][K]<<endl;
}