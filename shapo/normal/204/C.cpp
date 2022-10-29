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

#define maxn 201000
#define maxc 26

using namespace std;

int n;
char a[maxn], b[maxn];
double num_str, res_str;
long long num[maxn][maxc], num_r[maxn][maxc];

int main(){

	scanf("%d", &n);
	scanf(" %s %s", a, b);
	//for(int i = 0; i < n; ++i)a[i] = b[i] = 'A';
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 26; ++j){
			num[i][j] = num[i - 1][j];
			if(b[i - 1] == j + 'A')num[i][j] += (long long)i;
			//printf("num[%d][%d] = %lld\n", i, j, num[i][j]);
		}
	for(int i = 0; i < 26; ++i)num_r[n + 1][i] = 0;
	for(int i = n; i > 0; --i)
		for(int j = 0; j < 26; ++j){
			num_r[i][j] = num_r[i + 1][j];
			if(b[i - 1] == j + 'A')num_r[i][j] += (long long)(n - i + 1);
			//printf("num_r[%d][%d] = %lld\n", i, j, num_r[i][j]);
		}
	for(long long i = 1; i <= n; ++i)num_str = num_str + double(i * i);
	//printf("num_str = %lf\n", num_str);
	for(int i = 1; i <= n; ++i){
		long long aa = num[i - 1][a[i - 1] - 'A'], bb = num_r[i + 1][a[i - 1] - 'A'];
		//printf("aa = %lld, bb = %lld\n", aa, bb);
		res_str = res_str + double(aa * (n - i + 1) + bb * i);
		if(a[i - 1] == b[i - 1])res_str = res_str + (double)((long long)i * (long long)(n - i + 1));
	}
	//printf("res_str = %lf\n", res_str);

	double res = (double)(res_str) / (double)(num_str);
	printf("%.15lf\n", res);

	return 0;
}