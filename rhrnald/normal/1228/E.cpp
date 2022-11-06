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

const int N = 1011;
const int MOD=1000000007;
#define mult(x,y) ((1ll*(x)*(y)%MOD))
int n,a;

ll dp[N][N];
ll p1[N], p2[N];
ll P[N];
ll rP[N];
ll rev(ll x) {
	if(x==1) return 1;
	return mult(MOD-1, mult(MOD/x, rev(MOD%x)));
}
void make() {
	P[0]=1;
	for(int i=1; i<=500; i++) P[i]=mult(P[i-1], i);
	rP[500]=817016;
	for(int i=500; i>=1; i--) rP[i-1]=mult(rP[i], i);

	p1[0]=1, p2[0]=1;
	for(int i=1; i<=500; i++) p1[i]=mult(p1[i-1], a);
	for(int i=1; i<=500; i++) p2[i]=mult(p2[i-1], a-1);
}
ll f(int n, int k) {
	return mult(P[n], mult(rP[n-k], rP[k]));
}
int main(void){
	scanf("%d%d", &n, &a);
	make();
	dp[0][0]=1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			dp[i][j]+=mult(dp[i-1][j], mult(p2[n-j], p1[j]-p2[j]));
			for(int k=j+1; k<=n; k++) {
				dp[i][k]+=mult(dp[i-1][j], mult(mult(f(n-j, n-k), p2[n-k]), p1[j]));
			}
		}
		for(int j=0; j<=n; j++) {
			dp[i][j]%=MOD;
			if(dp[i][j]<0) dp[i][j]+=MOD;
		}
	}
	printf("%lld", dp[n][n]);
}