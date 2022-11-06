#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m;

int x[100];

int dp[30][N+N];
bool vst[100];
int main(void){
	scanf("%d", &n);
	int nn=n+n;
	for(int i=0; i<nn; i++) scanf("%d",x+i);
	sort(x, x+nn);
	int sum=0;
	for(int i=2; i<nn; i++) sum+=x[i];

	for(int i=0; i<=n; i++)
		for(int j=0; j<=sum; j++)
			dp[i][j]=-1;
	dp[0][0]=0;
	for(int i=2; i<nn; i++) {
		for(int j=0; j<=sum; j++) {
			for(int k=1; k<=n-1; k++) {
				if(j>=x[i] && dp[k][j]<0 && dp[k-1][j-x[i]]>=0 && dp[k-1][j-x[i]]<i) dp[k][j]=i;
			}
		}
	}
	int ans=INF;
	for(int i=0; i<=sum; i++) 
		if(dp[n-1][i]>=0) ans=min(max(i, sum-i), ans);
	
/*	for(int i=0; i<=sum; i++) {
		for(int j=0; j<=nn; j++) {
			printf("%d ", dp[i][j]);
		}printf("\n");
		}*/
	
	int cur=sum-ans;
	for(int i=n-1; i>0; i--) {
		int idx=dp[i][cur];
		vst[idx]=true;
		cur=cur-x[idx];
	}

	printf("%d ", x[0]);
	for(int i=2; i<nn; i++) if(vst[i]) printf("%d ", x[i]); printf("\n");
	for(int i=nn-1; i>1; i--) if(!vst[i]) printf("%d ", x[i]);
	printf("%d", x[1]);
}