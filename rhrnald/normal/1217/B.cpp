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
void proc() {
	scanf("%d%d", &n, &m);
	int X=0, Y=0;
	for(int i=0; i<n; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		X=max(X, x);
		Y=max(Y, x-y);
	}
	if(m==0) {printf("0\n"); return;}
	if(m<=X) {printf("1\n"); return;}
	if(Y<=0) {printf("-1\n"); return;}

	printf("%d\n", (m-X+Y-1)/Y+1);
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}