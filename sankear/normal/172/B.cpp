#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

int d[100100];

int main(){
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, m, r;
	scanf("%d %d %d %d", &a, &b, &m, &r);
	for(int i = 0; i < m; i++){
		d[i] = -1;
	}
	d[r] = 0;
	for(int i = 1; ; i++){
		r = (a * r + b) % m;
		if(d[r] != -1){
			printf("%d\n", i - d[r]);
			return 0;
		}
		d[r] = i;
	}
	return 0;
}