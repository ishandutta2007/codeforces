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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n;
	scanf("%d", &n);
	if(n % 3 == 1){
		n--;
	}
	if(n % 3 == 2){
		n++;
	}
	int a, b;
	for(int i = 0; i <= n; i++){
		if(n >= 36 * i && (n - 36 * i) % 3 == 0){
			a = i;
			b = (n - 36 * i) / 3;
		}
	}
	printf("%d %d\n", a, b);
	return 0;
}