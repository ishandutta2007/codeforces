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
}
int main(void){
	int a,b,c,d,x,y;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &x, &y);
	int ans=0;
	for(int i=0;i<=min(a,d); i++) {
		ans=max(ans, i*x+min({d-i,b,c})*y);
	}
	printf("%d", ans);
}