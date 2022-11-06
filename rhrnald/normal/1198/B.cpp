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
int idx[N];
int y[N];

int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", x+i);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		int t;
		scanf("%d", &t);
		if(t==2) {
			scanf("%d", y+i);
		} else {
			scanf("%d", &t);
			scanf("%d", x+t);
			idx[t]=i;
		}
	}
	for(int i=m-1; i>=0; i--) {
		y[i]=max(y[i], y[i+1]);
	}
	for(int i=1; i<=n; i++) {
		printf("%d ", max(x[i], y[idx[i]]));
	}
}