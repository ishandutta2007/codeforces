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
ll n,k;
int m;
ll x[N];
int main(void){
	scanf("%lld%d%lld", &n, &m,&k);
	for(int i=0; i<m; i++) scanf("%lld", x+i);
	
	int cur=0;
	int cnt=0;
	while(cur<m) {
	//	x[cur]<=k*pg+cur  pg
		cnt++;
		ll pg=(x[cur]-cur+k-1)/k;
		cur=upper_bound(x, x+m, k*pg+cur)-x;

	}
	printf("%d", cnt);
}