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
int cnt[3][3];
int x[N], y[N];
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d", x+i, y+i);
	}
	int X=1000001;
	for(int i=1; i<=n; i++) x[i]+=X, y[i]+=X;
	if(n==2) {
		printf("%d\n%d", 1, 1);
		return 0;
	}
	while(true) {
		cnt[0][0]=0;
		cnt[1][0]=0;
		cnt[0][1]=0;
		cnt[1][1]=0;
		for(int i=1; i<=n; i++) {
			cnt[x[i]&1][y[i]&1]++;
		}
		int t=0;
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++) if(cnt[i][j]) t++;
		if(t>1) break;
		for(int i=1; i<=n; i++) x[i]/=2, y[i]/=2;
	}
	
	if(cnt[0][0]+cnt[1][1]>0 && cnt[1][0]+cnt[0][1]>0) {
		printf("%d\n", cnt[0][0]+cnt[1][1]);
		for(int i=1; i<=n; i++) {
			if((x[i]&1)==(y[i]&1)) printf("%d ", i);
		}
		return 0;
	}
	
	printf("%d\n", cnt[0][0]+cnt[0][1]);
	for(int i=1; i<=n; i++) {
		if((x[i]&1)==0) printf("%d ", i);
	}
	return 0;
}