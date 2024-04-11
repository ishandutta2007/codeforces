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

int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", x+i);
	for(int i=1; i<=n; i++) x[i]=x[i-1]+x[i];
	scanf("%d", &m);
	while(m--) {
		int a,b;
		scanf("%d%d", &a, &b);
		printf("%d\n", (x[b]-x[a-1])/10);
	}
}