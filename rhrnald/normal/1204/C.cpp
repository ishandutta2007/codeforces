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

const int N = 111;
const int M=1010101;
int n,m;
int x[M];
vector<int> G[N];
string s;

int dis[N][N];
void make() {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			dis[i][j]=INF;

	for(int i=1; i<=n; i++) {
		dis[i][i]=0;
		for(int nxt : G[i]) {
			dis[i][nxt]=1;
		}
	}

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++) {
				dis[j][k]=min(dis[j][k], dis[j][i]+dis[i][k]);
			}
}

int dp[M];
int prv[M];
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		cin >> s;
		for(int j=1; j<=n; j++) {
			if(s[j-1]=='1') {
				G[i].push_back(j);
			}
		}
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++) scanf("%d", x+i);
	
	make();
	dp[0]=1;
	prv[0]=-1;
	for(int i=1; i<m; i++) {
		dp[i]=INF;
		for(int j=max(0,i-n); j<i; j++) {
			if(dis[x[j]][x[i]]==i-j) {
				if(dp[i]>=dp[j]+1) prv[i]=j, dp[i]=dp[j]+1;
			}
		}
	}
	printf("%d\n", dp[m-1]);
	vector<int> v;
	int cur=m-1;
	while(cur>=0) {v.push_back(cur); cur=prv[cur];}
	reverse(all(v));

	for(int e : v) printf("%d ", x[e]);
}