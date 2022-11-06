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
	for(int i=0; i<n; i++) scanf("%d", x+i);
	sort(x, x+n, greater<int>());
	if(x[0]<x[1]+x[2]) {
		printf("YES\n");
		printf("%d", x[0]);
		for(int i=2; i<n; i++) printf(" %d", x[i]);
		printf(" %d", x[1]);
	} else {
		printf("NO");
	}
}