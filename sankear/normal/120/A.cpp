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

char s[100];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
  scanf("%s\n%d", s, &t);
	if(strcmp(s, "front") == 0){
		if(t == 1){
			printf("L\n");
			return 0;
		}
		printf("R\n");
		return 0;
	}
	if(t == 1){
		printf("R\n");
		return 0;
	}
	printf("L\n");
	return 0;
}