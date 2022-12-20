// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2010,MAX=1e4,inf=1e9;

pii p[maxn];
int dp[2][10][MAX];
int dg[MAX][4],emp[MAX],tn[4];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i].F>>p[i].S;
    }
    for(int i=0;i<MAX;i++){
	int x=i;
	emp[i]=-1;
	for(int j=0;j<4;j++,x/=10){
	    dg[i][j]=x%10;
	    if(dg[i][j]==0) emp[i]=j;
	}
    }
    tn[0]=1;
    for(int i=1;i<4;i++)
	tn[i]=10*tn[i-1];
    for(int k=1;k<MAX;k++){
	for(int j=1;j<=9;j++){
	    dp[n&1][j][k]=inf;
	    for(int w=0;w<4;w++){
		if(dg[k][w]==0) continue;
		dp[n&1][j][k]=min(dp[n&1][j][k],abs(j-dg[k][w])+dp[n&1][dg[k][w]][k-dg[k][w]*tn[w]]);
	    }
	}
    }
    for(int i=n-1;i>=0;i--){
	bool o=i&1;
	int A=p[i].F,B=p[i].S;
	for(int j=1;j<=9;j++){
	    for(int k=0;k<MAX;k++){
		if(emp[k]==-1) dp[o][j][k]=inf;
		else dp[o][j][k]=abs(j-A)+dp[!o][A][k+B*tn[emp[k]]];
	    }
	}
	for(int k=1;k<MAX;k++){
	    for(int j=1;j<=9;j++){
		for(int w=0;w<4;w++){
		    if(dg[k][w]==0) continue;
		    dp[o][j][k]=min(dp[o][j][k],abs(j-dg[k][w])+dp[o][dg[k][w]][k-dg[k][w]*tn[w]]);
		}
	    }
	}
    }
    cout<<dp[0][1][0]+2*n<<endl;
    return 0;
}