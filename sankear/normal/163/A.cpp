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

const ll MOD = (ll)(1e9 + 7);

char s[5050], t[5050];
ll d[5001][5001], sd[5001];

inline void norm(ll &a){
	while(a >= MOD){
		a -= MOD;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s %s", s, t);
	int n = strlen(s), m = strlen(t);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i - 1] == t[j - 1]){
				d[i][j] = sd[j - 1] + 1;
				norm(d[i][j]);
			}
		}
		for(int j = 1; j <= m; j++){
			sd[j] = sd[j - 1] + d[i][j];
			norm(sd[j]);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans += d[i][j];
			norm(ans);
		}
	}
	cout << ans << endl;
	return 0;
}