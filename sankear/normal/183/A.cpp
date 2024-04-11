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

typedef long long ll;

char s[200200][10];

inline char f(char ch){
	if(ch == 'R'){
		return 'L';
	}
	if(ch == 'L'){
		return 'R';
	}
	if(ch == 'D'){
		return 'U';
	}
	return 'D';
}

inline int len(int x1, int y1, int x2, int y2){
	if(abs(x1 - x2) != abs(y1 - y2)){
		while(true);
	}
	return abs(x1 - x2) + 1;
}

int main(){
	//freopen("gcd.in", "r", stdin);
	//freopen("gcd.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
		if(strcmp(s[i], "ULDR") == 0){
			continue;
		}
		for(int j = 0; j < (int)strlen(s[i]); j++){
			s[i][j] = f(s[i][j]);
		}
	}
	reverse(s, s + n);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(s[i], "UL") == 0){
			x1--;
			y2++;
			y3++;
		}
		if(strcmp(s[i], "UR") == 0){
			y1++;
			y2++;
			x3++;
		}
		if(strcmp(s[i], "DL") == 0){
			x1--;
			x2--;
			y3--;
		}
		if(strcmp(s[i], "DR") == 0){
			y1--;
			x2++;
			x3++;
		}
		if(strcmp(s[i], "ULDR") == 0){
			x1--;
			y2++;
			x3++;
		}
	}
	ll ans = (ll)len(x1, y1, x2, y2) * len(x2, y2, x3, y3);
	cout << ans << endl;
	return 0;
}