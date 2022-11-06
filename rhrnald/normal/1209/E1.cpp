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

const int N = 3000;
int n,m;
int x[N][N];
int dp[30][4100];

int cur[4100];

void rotate(int idx) {
	int t=x[idx][0];
	for(int i=0;i<m-1;i++) x[idx][i]=x[idx][i+1];
	x[idx][m-1]=t;
}
int sum(int idx, int b) {
	int ret=0;
	for(int i=0; i<m; i++) {
		if(b&1) ret+=x[idx][i];
		b/=2;
	}
	return ret;
}
vector<pii> v;
void proc() {
	scanf("%d%d", &m, &n);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) {
			scanf("%d", x[j]+i);
		}

	v.clear();
	for(int i=0; i<n; i++) {
		int M=0;
		for(int j=0;j<m;j++) M=max(M, x[i][j]);
		v.push_back({M,i});
	}
	sort(all(v), greater<pii>());
	int num=min(n, m);

	int B=1<<m;
	for(int i=0; i<=num; i++)
		for(int j=0; j<B; j++) dp[i][j]=0;

	for(int i=0; i<num; i++) {
		for(int k=0;k<B;k++) cur[k]=0;
		int idx=v[i].second;
		for(int j=0; j<m; j++) {
			rotate(idx);
			for(int k=0; k<B; k++) cur[k]=max(cur[k], sum(idx,k));
		}

		for(int k=0; k<B; k++) {
			for(int t=0; t<B; t++) {
				if(k&(~t)) continue;
				dp[i+1][t&(~k)]=max(dp[i+1][t&(~k)], dp[i][t]+cur[k]);
			}
		}
	}
	printf("%d\n", dp[num][0]);
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}