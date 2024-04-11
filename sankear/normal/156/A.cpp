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

const int inf = (int)1e9;

char s[2020], t[2020];

inline char get(int a, int b){
	if(a < 0 || a >= b){
		return '?';
	}
	return s[a];
}

int main(){
	//freopen("tests.in", "r", stdin);
	//freopen("tests.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s %s", s, t);
	int n = strlen(s), m = strlen(t);
	int ans = inf;
	for(int i = -n - m - 100; i < n + m + 100; i++){
		int res = 0, len = 0;
		for(int j = i; len < m && j < n + m + 100; j++){
			len++;
			if(get(j, n) != t[j - i]){
				res++;
			}
		}
		res += m - len;
		ans = min(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}