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
const int MOD = 998244353;
const int N = 1010;
int n,m;
int x[N];

ll cnt[N][N];
ll ans[100100];
ll f(int k) {
	for(int i=0; i<n; i++) cnt[i][1]=1;
	for(int i=n-2; i>=0; i--) cnt[i][1]=(cnt[i][1]+cnt[i+1][1])%MOD;

	for(int t=2; t<=m; t++) {
		int cur=0;
		for(int i=0; i<n; i++) {
			while(cur<=i || (cur<n && x[cur]<x[i]+k)) cur++;
			cnt[i][t]=cnt[cur][t-1];
		}
		for(int i=n-2; i>=0; i--) cnt[i][t]=(cnt[i][t]+cnt[i+1][t])%MOD;
	}
	return cnt[0][m];
}

int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	sort(x, x+n);
	int M=100000/(m-1);
	for(int k=0; k<=M; k++) ans[k]=f(k);
//	f(0);

	ll sum=0;
	for(int k=0; k<=M; k++) sum=(sum+k*(ans[k]-ans[k+1]))%MOD;
	printf("%lld", (sum%MOD+MOD)%MOD);
}