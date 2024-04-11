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
int n,m,x,y;
vector<pii> v;

ll dp[100][100100];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back({x, y});
	}
	sort(all(v));
	dp[0][0]=0;
	for(int j=1; j<=m; j++) dp[0][j]=LINF;
	for(int i=0; i<n; i++) {
		x=v[i].first, y=v[i].second;
		for(int j=1; j<=m; j++) {
			dp[i+1][j]=dp[i][j];
		}
		for(int d=0; d<=m; d++) {
			dp[i+1][min(m,x+y+d)]=min(dp[i+1][min(m,x+y+d)], d+dp[i][max(0, x-y-d-1)]);
		}

		for(int j=m-1; j>=0; j--) dp[i+1][j]=min(dp[i+1][j], dp[i+1][j+1]);
	}

	printf("%lld", dp[n][m]);
}