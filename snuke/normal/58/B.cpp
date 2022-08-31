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
#define drep(i,o,n) for(int i=o; i>n; i--)
#define pb push_back
using namespace std;



int main () {
	int n, i = 2;
	scanf("%d",&n);
	printf("%d",n);
	for (; i <= n; i++) {
		if (n % i == 0) {
			n /= i;
			printf(" %d",n);
			i--;
		}
	}
	return 0;
}