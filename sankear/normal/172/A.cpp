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

const ll hx = (ll)(2e5 + 3);

char s[30300][22];
ll h[30300][22];

int main(){
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}
	int len = strlen(s[0]);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < len; j++){
			h[i][j] = (j > 0 ? h[i][j - 1] : 0) * hx + s[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= len; i++){
		bool fl = true;
		for(int j = 1; j < n; j++){
			if(h[j][i - 1] != h[0][i - 1]){
				fl = false;
				break;
			}
		}
		if(fl){
			ans = i;
			continue;
		}
		break;
	}
	printf("%d\n", ans);
	return 0;
}