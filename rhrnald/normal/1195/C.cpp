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

int x[2][N];
ll ans[2][N];

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", x[0]+i);
	for(int i=0; i<n; i++) scanf("%d", x[1]+i);
	
	ans[0][n-1]=x[0][n-1];
	ans[1][n-1]=x[1][n-1];
	for(int i=n-2; i>=0; i--) {
		for(int t=0; t<2; t++) {
			ans[t][i]=max(ans[t][i+1], x[t][i]+ans[1-t][i+1]);
		}
	}
	printf("%lld", max(ans[0][0], ans[1][0]));
}