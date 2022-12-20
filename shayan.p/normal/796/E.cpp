// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int maxn=1100;
vector<vector<vector<int> > > dp[maxn];

int sum[3][maxn],sumb[maxn];
bool a[3][maxn],both[maxn];
int n,p,k;

void input_and_pre(){
	cin>>n>>p>>k;
	p=min(p,2*((n/k)+1));
	
	REP(i,maxn){
		dp[i].resize(p+1);
		REP(j,(p+1)){
			dp[i][j].resize(k+1);
			REP(kk,(k+1)){
				dp[i][j][kk].resize(2);
			}
		}
	}
	int r;cin>>r;
	REP(i,r){
		int x;cin>>x;
		a[0][x]=1;
		both[x]=1;
	}
	int s;cin>>s;
	REP(i,s){
		int x;cin>>x;
		a[1][x]=1;
		both[x]=1;
	}
	FOR(i,1,maxn-1){// maxn instead of n so that we dont concern about going out of corners
		sumb[i]=sumb[i-1]+both[i];
		sum[0][i]=sum[0][i-1]+a[0][i];
		sum[1][i]=sum[1][i-1]+a[1][i];
	}
}
int main(){
	input_and_pre();
	
	FORD(i,n,1){
		dp[i][0][0][0]=0;
		dp[i][0][0][1]=0;
		FOR(j,1,k-1){//0 glances
			FOR(m,0,1){
				dp[i][0][j][m]=sum[m][i+j-1]-sum[m][i-1];
			}
		}
		
		FOR(j,1,p){
			dp[i][j][0][0]=max(dp[i+1][j][0][0],max(a[0][i]+dp[i+1][j-1][k-1][0],a[1][i]+dp[i+1][j-1][k-1][1]));
			dp[i][j][0][1]=dp[i][j][0][0];
			FOR(kk,1,k-1){
				FOR(m,0,1){//i start // j glances // kk seen // m who
					if(a[m][i]==1)dp[i][j][kk][m]=dp[i+1][j][max(int(0),kk-1)][m]+1;
					else{
						int A,B,C;
						A=dp[i+1][j][max(int(0),kk-1)][m];
						B=a[m][i]+dp[i+1][j-1][k-1][m];
						C=(sumb[i+kk-1]-sumb[i-1])+dp[i+kk][j-1][k-kk][!m];
						dp[i][j][kk][m]=max(A,max(B,C));
					}
				}
			}
		}
	}
	cout<<dp[1][p][0][0];
}