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

char s[2000];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  scanf("%s", s);
	int n = strlen(s);
	int cur = 0;
	for(int i = 0; i < n; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			if(s[i - 1] == '/'){
				cur--;
				for(int j = 0; j < 2 * cur; j++){
					printf(" ");
				}
				printf("</%c>\n", s[i]);
				continue;
			}
			for(int j = 0; j < 2 * cur; j++){
				printf(" ");
			}
			printf("<%c>\n", s[i]);
			cur++;
		}
	}
	return 0;
}