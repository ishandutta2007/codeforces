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

char s[200];
int val[200], ans[200];

inline int inv(int a){
	for(int i = 7; i >= 0; i--){
		if(a >= (1 << i)){
			val[i] = 1;
			a -= (1 << i);
		}
		else{
			val[i] = 0;
		}
	}
	int l = 0;
	int r = 7;
	while(l < r){
		swap(val[l++], val[r--]);
	}
	int res = 0;
	for(int i = 0; i <= 7; i++){
		res += (1 << i) * val[i];
	}
	return res;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s);
	int n = strlen(s);
	for(int i = n - 1; i >= 0; i--){
		int prev;
		if(i == 0){
			prev = 0;
		}
		else{
			prev = inv((int)s[i - 1]);
		}
		for(int j = 0; j < 256; j++){
			if(inv((prev - j + 256) % 256) == (int)s[i]){
				ans[i] = j;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}