#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 105

using namespace std;

int n, m;
bool ok[maxn][maxn];
double num1[maxn], num2[maxn];
int best1[maxn], best2[maxn];
int q[maxn];
int beg, en;

int go(int ft, double* res, int* sm){
	beg = 1;
	en = 0;
	for(int i = 1; i <= n; ++i)sm[i] = n * n;
	q[++en] = ft;
	sm[ft] = 0;
	while(beg <= en){
		for(int i = 1; i <= n; ++i){
			if(ok[q[beg]][i] && sm[i] == n * n){
				sm[i] = sm[q[beg]] + 1;
				q[++en] = i;
			}
		}
		++beg;
	}
	res[ft] = 1.0;
	for(int i = 2; i <= en; ++i){
		res[q[i]] = 0.0;
		for(int j = 1; j <= n; ++j)
			if(ok[q[i]][j] && sm[q[i]] == sm[j] + 1)res[q[i]] += res[j];
	}
	return 0;
}

int input_data(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		ok[a][b] = ok[b][a] = true;
	}
	return 0;
}

int proc(int x, double& upd){
	double mid = 0.0;
	for(int i = 1; i <= n; ++i)
		if(ok[x][i]){
			if(best1[n] == best1[x] + best2[i] + 1)
				mid = mid + num1[x] * num2[i];
			if(best1[n] == best2[x] + best1[i] + 1)
				mid = mid + num2[x] * num1[i];			
		}
	mid = mid / num1[n];
	upd = max(upd, mid);
	return 0;
}

int main(){
	input_data();
	go(1, num1, best1);
	go(n, num2, best2);
	double max_r = 0.0;
	for(int i = 1; i <= n; ++i)
		proc(i, max_r);
	printf("%.10lf\n", max_r);
	return 0;
}