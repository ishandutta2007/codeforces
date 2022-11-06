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
	for(int i=0; i<n; i++) scanf("%d", x+i);
	sort(x, x+n);

	int l=0, r=n-1;
	while(l<r) {
		int cl=l+1;
		int cr=n-r;
		if(cr>cl) {
			if(1ll*(x[l+1]-x[l])*cl<m) {
				m-=1ll*(x[l+1]-x[l])*cl;
				l++;
			} else {
				printf("%lld\n", x[r]-(x[l]+m/cl));
				return 0;
			}
		} else {
			if(1ll*(x[r]-x[r-1])*cr<m) {
				m-=1ll*(x[r]-x[r-1])*cr;
				r--;
			} else {
				printf("%lld\n", (x[r]-m/cr)-x[l]);
				return 0;
			}
		}
	}
	printf("0");
}