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
int a, b,c,d,k;
void proc() {
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
	int t1=(a-1)/c+1;
	int t2=(b-1)/d+1;
	if(t1+t2<=k) printf("%d %d\n", t1, t2);
	else printf("-1\n");
}
int main(void){
	int tc;scanf("%d", &tc);
	while(tc--) proc();
}