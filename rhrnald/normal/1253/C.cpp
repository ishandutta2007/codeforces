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
int x[N];

ll ans;
ll sum[N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	sort(x, x+n);
	
	for(int i=0; i<n; i++) {
		sum[i%m]+=x[i];
		ans+=sum[i%m];
		printf("%lld ", ans);
	}
}