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

const int inf = (int)1e9;

int sz;
char s[1000100];
int d[1000100][2], p[1000100][2];
char ch[1000100];
int num[1000100], val[1000100];

void path(int n, int fl){
	if(n == 0){
		if(fl == 1){
			ch[sz] = '+';
			num[sz++] = val[0] + 1;
		}
		return;
	}
	if(fl == 0){
		if(p[n][fl] == 1){
			path(n - 1, 0);
			if(s[n - 1] == '1'){
				ch[sz] = '+';
				num[sz++] = val[n - 1];
			}
			return;
		}
		path(n - 1, 1);
		if(s[n - 1] == '1'){
			ch[sz] = '-';
			num[sz++] = val[n - 1];
		}
		else{
			ch[sz] = '-';
			num[sz++] = val[n - 1] + 1;
		}
		return;
	}
	if(p[n][fl] == 1){
		path(n - 1, 1);
		if(s[n - 1] == '0'){
			ch[sz] = '-';
			num[sz++] = val[n - 1];
		}
		return;
	}
	if(p[n][fl] == 2){
		path(n - 1, 0);
		if(s[n - 1] == '0'){
			ch[sz] = '+';
			num[sz++] = val[n - 1];
		}
		else{
			ch[sz] = '+';
			num[sz++] = val[n - 1] + 1;
		}
		return;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	val[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		val[i] = val[i + 1] + 1;
	}
	for(int i = 1; i <= n; i++){
		d[i][0] = d[i][1] = inf;
	}
	d[0][1] = 1;
	for(int i = 0; i < n; i++){
		if(d[i][0] + (s[i] == '1') < d[i + 1][0]){
			d[i + 1][0] = d[i][0] + (s[i] == '1');
			p[i + 1][0] = 1;
		}
		if(d[i][1] + 1 < d[i + 1][0]){
			d[i + 1][0] = d[i][1] + 1;
			p[i + 1][0] = 2;
		}
		if(d[i][1] + (s[i] == '0') < d[i + 1][1]){
			d[i + 1][1] = d[i][1] + (s[i] == '0');
			p[i + 1][1] = 1;
		}
		if(d[i][0] + 1 < d[i + 1][1]){
			d[i + 1][1] = d[i][0] + 1;
			p[i + 1][1] = 2;
		}
	}
	sz = 0;
	path(n, 0);
	printf("%d\n", sz);
	for(int i = 0; i < sz; i++){
		printf("%c2^%d\n", ch[i], num[i]);
	}
	return 0;
}