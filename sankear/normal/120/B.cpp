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

int a[2000];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n, k;
	scanf("%d %d", &n, &k);
	k--;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	while(a[k] == 0){
		k = (k + 1) % n;
	}
	printf("%d\n", k + 1);
	return 0;
}