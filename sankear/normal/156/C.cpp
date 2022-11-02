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

const int MOD = (int)(1e9 + 7);
const int maxn = 100;
const int maxsum = maxn * 26;

char s[200];
int d[200][2700], sd[200][2700];

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

inline void solve(){
	scanf("%s", s);
	int n = strlen(s);
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += s[i] - 'a' + 1;
	}
	int ans = d[n][sum] - 1;
	if(ans < 0){
		ans += MOD;
	}
	printf("%d\n", ans);
}

inline void init(){
	d[0][0] = 1;
	for(int i = 0; i <= maxsum; i++){
		sd[0][i] = (i > 0 ? sd[0][i - 1] : 0) + d[0][i];
	}
	for(int i = 1; i <= maxn; i++){
		for(int j = 1; j <= maxsum; j++){
			int can = max(j - 26, 0);
			d[i][j] = sd[i - 1][j - 1] - (can > 0 ? sd[i - 1][can - 1] : 0) + MOD;
			norm(d[i][j]);
			sd[i][j] = (j > 0 ? sd[i][j - 1] : 0) + d[i][j];
			norm(sd[i][j]);
		}
	}
}

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	init();
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		solve();
	}
	return 0;
}