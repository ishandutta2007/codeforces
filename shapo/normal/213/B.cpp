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

#define maxn 150

using namespace std;

long long ck[maxn][maxn];
const long long osn = 1000000007;
long long res = 0;
int n, x;
int a[10];
long long f[maxn][11];

int init(){
	ck[0][0] = 1;
	for(int i = 1; i < maxn; ++i){
		ck[i][0] = ck[i - 1][0];
		for(int j = 1; j <= i; ++j)
			ck[i][j] = (ck[i - 1][j - 1] + ck[i - 1][j]) % osn;
	}
	return 0;
}

int input_data(){
	scanf("%d", &n);
	for(int i = 0; i < 10; ++i){
		scanf("%d", &a[i]);
		x += a[i];
	}
	return 0;
}

long long proc(int sum){
	//printf("sum = %d\n", sum);
	long long csum (0);
	for(int dg = 1; dg < 10; ++dg){
		long long cur_sum (1);
		int tmp[10], cur (sum - 1);
		for(int i = 0; i < 10; ++i)tmp[i] = a[i];
		if(tmp[dg])--tmp[dg];
		memset(f, 0, sizeof(f));
		f[0][10] = 1;
		for(int ii = 9; ii >= 0; --ii)
			for(int jj = 0; jj <= cur; ++jj)
				for(int kk = tmp[ii]; kk <= jj; ++kk)
					f[jj][ii] = (f[jj][ii] + f[jj - kk][ii + 1] * ck[jj][kk]) % osn;
		cur_sum = f[cur][0];
		//printf("dg = %d, cur_sum = %lld\n", dg, cur_sum);
		csum = (csum + cur_sum) % osn;
	}
	return csum;
}

int make_ans(){
	for(int i = x; i <= n; ++i)
		res = (res + proc(i)) % osn;
	return 0;
}

int main(){
	init();
	input_data();
	make_ans();
	int dres = (int)res;
	printf("%d\n", dres);
	return 0;
}