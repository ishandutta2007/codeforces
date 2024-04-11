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

int used[30], need[30];
char s[100100], t[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s %s", s, t);
	int n = strlen(s);
	int m = strlen(t);
	if(n < m){
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < m; i++){
		need[t[i] - 'a']++;
	}
	for(int i = 0; i < m; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			used[s[i] - 'a']++;
		}
	}
	int ans = 0;
	for(int i = 0; i < n - m + 1; i++){
		bool fl = true;
		for(int j = 0; j < 26; j++){
			if(used[j] > need[j]){
				fl = false;
				break;
			}
		}
		if(fl){
			ans++;
		}
		if(s[i] >= 'a' && s[i] <= 'z'){
			used[s[i] - 'a']--;
		}
		if(i + m < n){
			if(s[i + m] >= 'a' && s[i + m] <= 'z'){
				used[s[i + m] - 'a']++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;	
}