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

char lst[6] = {'A', 'O', 'Y', 'E', 'U', 'I'};
char s[200];
bool used[200];

inline char f(char ch){
	if(ch >= 'A' && ch <= 'Z'){
		ch = ch + 'a' - 'A';
	}
	return ch;
}

inline bool bad(char ch){
	for(int i = 0; i < 6; i++){
		if(lst[i] == ch || f(lst[i]) == ch){
			return true;
		}
	}
	return false;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		if(bad(s[i])){
			used[i] = true;
		}
	}
	for(int i = 0; i < n; i++){
		if(!used[i]){
			printf(".%c", f(s[i]));
		}
	}
	printf("\n");
	return 0;
}