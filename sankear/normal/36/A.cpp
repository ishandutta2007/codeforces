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
int lst[200];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n;
	scanf("%d %s", &n, s);
	int k = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			lst[k++] = i;
		}
	}
	for(int i = 1; i < k; i++){
		if(lst[i] - lst[i - 1] != lst[1] - lst[0]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}