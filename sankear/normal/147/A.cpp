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

char *w[20000];
char s[20000], r[20000];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s);
	int n = strlen(s);
	s[n] = ' ';
	int k = 0, clen = 0;
	for(int i = 0; i <= n; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			r[clen++] = s[i];
		}
		else{
			if(clen > 0){
				w[k] = (char*)malloc(sizeof(char) * (clen + 1));
				r[clen] = '\0';
				strcpy(w[k++], r);
				clen = 0;
			}
			if(s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?'){
				w[k] = (char*)malloc(sizeof(char) * 2);
				w[k][0] = s[i];
				w[k++][1] = '\0';
			}
		}
	}
	bool need = false;
	for(int i = 0; i < k; i++){
		int len = strlen(w[i]);
		if(len == 1 && (w[i][0] == '.' || w[i][0] == ',' || w[i][0] == '!' || w[i][0] == '?')){
			printf("%s ", w[i]);
			need = false;
		}
		else{
			if(need){
				printf(" ");
			}
			printf("%s", w[i]);
			need = true;
		}
	}
	printf("\n");
	return 0;
}