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
#include <queue>

using namespace std;

char s[300];
int lst1[300], lst2[300];

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d %s", &n, s);
	for(int i = 0; i < n; i++){
		lst1[i] = s[i] - '0';
	}
	for(int i = n; i < 2 * n; i++){
		lst2[i - n] = s[i] - '0';
	}
	sort(lst1, lst1 + n);
	sort(lst2, lst2 + n);
	bool fl = true;
	for(int i = 0; i < n; i++){
		if(lst1[i] >= lst2[i]){
			fl = false;
			break;
		}
	}
	if(fl){
		printf("YES\n");
		return 0;
	}
	fl = true;
	for(int i = n - 1; i >= 0; i--){
		if(lst1[i] <= lst2[i]){
			fl = false;
			break;
		}
	}
	if(fl){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}