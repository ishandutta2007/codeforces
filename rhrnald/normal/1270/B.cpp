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
int n,m,M;
int x[N],y[N],z[N];
void proc() {
	scanf("%d", &n);

	M=-INF;
	m=INF;
	for(int i=0; i<n; i++) {
		scanf("%d", x+i);
	}
	for(int i=0; i<n-1; i++) {
		if(abs(x[i]-x[i+1])>1) {
			printf("YES\n%d %d\n", i+1, i+2);
			return;
		}
	}
	printf("NO\n");
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--) proc();
}