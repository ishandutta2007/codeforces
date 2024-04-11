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
int L,n,m;

int main(void){
	scanf("%d%d%d", &L, &n, &m);
	m=m*5;
	int d=__gcd(n,m);
	if(L>n*m) {printf("%d", L%d); return 0;}

	int ans=L;
	for(int i=0; i<n; i++) {
		int cur=i*m;
		if(cur>L) break;
		ans=min(ans, L-(L-cur)/n*n-cur);
	}
	cout << ans;
}