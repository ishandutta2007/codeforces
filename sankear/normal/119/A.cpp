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

bool d[200][2];

inline int gcd(int a, int b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	for(int i = 1; i <= n; i++){
		int cur = gcd(i, a);
		d[i][0] = !d[i - cur][1];
		cur = gcd(i, b);
		d[i][1] = !d[i - cur][0];
	}
	if(d[n][0]){
		printf("0\n");
		return 0;
	}
	printf("1\n");
	return 0;
}