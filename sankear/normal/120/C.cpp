#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		for(int j = 0; j < 3; j++){
			if(a >= k){
				a -= k;
			}
		}
		ans += a;
	}
	printf("%d\n", ans);
	return 0;
}