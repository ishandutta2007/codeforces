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
	scanf("%d", &n);
	
	ll X=0, Y=0;
	for(int i=0; i<n; i++) {
		ll m;
		scanf("%lld", &m);
		X+=m;
		Y^=m;
	}
	printf("2\n%lld %lld\n", Y, X+Y);
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--) proc();
}