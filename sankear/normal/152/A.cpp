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

char a[200][200];

int main(){
	//freopen("tests.in", "r", stdin);
	//freopen("tests.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool fl = false;
		for(int j = 0; j < m; j++){
			bool good = true;
			for(int z = 0; z < n; z++){
				if(a[z][j] > a[i][j]){
					good = false;
					break;
				}
			}
			if(good){
				fl = true;
				break;
			}
		}
		if(fl){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}