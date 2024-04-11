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
	if(__gcd(n,m)==1) printf("Finite\n");
	else printf("Infinite\n");
}
int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--) proc();
}