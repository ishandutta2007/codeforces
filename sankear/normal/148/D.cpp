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

bool used[1010][1010][2];
double d[1010][1010][2];

double calc(int n, int m, int step){
	if(n + m == 0){
		return 0;
	}
	if(n == 0){
		return 0;
	}
	if(m == 0){
		if(step == 0){
			return 1;
		}
		return 0;
	}
	if(used[n][m][step]){
		return d[n][m][step];
	}
	used[n][m][step] = true;
	if(step == 0){
		return d[n][m][step] = ((double)n) / (n + m) + ((double)m) / (n + m) * calc(n, m - 1, 1);
	}
	double res = ((double)n) / (n + m - 1) * calc(n - 1, m - 1, 0);
	if(m >= 2){
		res += ((double)(m - 1)) / (n + m - 1) * calc(n, m - 2, 0);
	}
	return d[n][m][step] = ((double)m) / (n + m) * res;
}

int main(){
	//freopen("border.in", "r", stdin);
	//freopen("border.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	double ans = calc(n, m, 0);
	printf("%.18lf\n", ans);
	return 0;
}