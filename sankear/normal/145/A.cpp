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

char s[100100], t[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s %s", s, t);
	int n = strlen(s);
	int sz1 = 0, sz2 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			if(s[i] == '4'){
				sz1++;
			}
			else{
				sz2++;
			}
		}
	}
	int ans = min(sz1, sz2);
	sz1 = sz2 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			if(s[i] == '4'){
				if(sz1 < ans){
					s[i] = '7';
					sz1++;
				}
			}
			else{
				if(sz2 < ans){
					s[i] = '4';
					sz2++;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}