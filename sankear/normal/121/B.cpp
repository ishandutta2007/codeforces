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

char s[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n, k;
	scanf("%d %d\n%s", &n, &k, s);
	int i = 0;
	while(i < n){
		if(i + 1 < n){
			if(s[i] == '4' && s[i + 1] == '7' && k > 0){
				if(i % 2 == 0){
					s[i] = '4';
					s[i + 1] = '4';
					i++;
					k--;
					continue;
				}
				if(i > 0 && s[i - 1] == '4'){
					if(k % 2 == 0){
						printf("%s\n", s);
						return 0;
					}
					s[i] = '7';
					s[i + 1] = '7';
					printf("%s\n", s);
					return 0;
				}
				else{
					s[i] = '7';
					s[i + 1] = '7';
					i++;
					k--;
					continue;
				}
			}
		}
		i++;
	}
	printf("%s\n", s);
	return 0;
}