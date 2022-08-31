#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,o,n) for(int i=o; i<n; i++)
#define drep(i,o,n) for(int i=o; i>=n; i--)
#define pb push_back
using namespace std;

int x[100001];

int main () {
    //freopen("in", "r", stdin);
	int n, a, m, ma = 0;
	scanf("%d",&n);
	
	m = n/2 + n%2;
	
	rep(i,m){
		scanf("%d",&a);
		if (a-i > 0) {
			x[a-i]++;
			ma = max(ma, x[a-i]);
		}
	}
	drep(i,n/2-1,0){
		scanf("%d",&a);
		if (a-i > 0) {
			x[a-i]++;
			ma = max(ma, x[a-i]);
		}
	}
	
	printf("%d\n",n-ma);
	return 0;
}