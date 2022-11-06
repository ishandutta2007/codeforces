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
int n;
ll m;

int x[N];

int main(void){
	scanf("%d%lld", &n, &m);
	ll cur=1ll*n*(n+1)/2;
	if(m<cur) {printf("-1"); return 0;}
	for(int i=1; i<=n; i++) x[i]=i;
	int l=1, r=n;
	while(l<r) {
		if(cur+r-l<=m) {
			swap(x[l], x[r]);
			cur+=r-l;
			l++, r--;
		} else {
			int rr=m-cur+l;
			cur+=rr-l;
			swap(x[l], x[rr]);
			break;
		}
	}
	printf("%lld\n", cur);
	for(int i=1; i<=n; i++) printf("%d ", i); printf("\n");
	for(int i=1; i<=n; i++) printf("%d ", x[i]);
}