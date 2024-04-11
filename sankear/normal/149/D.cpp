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

#define mp make_pair
#define pb push_back
#define next _next

typedef long long ll;
typedef pair <int, int> pii;

const ll MOD = (ll)(1e9 + 7);

char s[1000];
int stack[1000], next[1000];
bool usedd[1000][1000], usedf[1000][1000];
ll d[1000][1000][2][2][2][2];
ll f[1000][1000][2][2];
ll nd[2][2][2][2];

inline void norm(ll &a){
	while(a >= MOD){
		a -= MOD;
	}
}

inline bool check1(int a, int b, int c, int d){
	if(a == 0 || c == 1){
		return true;
	}
	if(b == d){
		return false;
	}
	return true;
}

inline bool check2(int a, int b, int c, int d){
	if(a == 1 || c == 1){
		return true;
	}
	if(b == d){
		return false;
	}
	return true;
}

inline bool check3(int a, int b, int c, int d){
	if(a == 0 || c == 0){
		return true;
	}
	if(b == d){
		return false;
	}
	return true;
}

void calcd(int l, int r);

void calcf(int l, int r){
	if(usedf[l][r]){
		return;
	}
	usedf[l][r] = true;
	if(l + 1 == r){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				f[l][r][i][j] = 1;
			}
		}
		return;
	}
	calcd(l + 1, r - 1);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int h = 0; h < 2; h++){
					for(int t = 0; t < 2; t++){
						for(int x = 0; x < 2; x++){
							if(check2(i, j, z, h) && check3(i, j, t, x)){
								f[l][r][i][j] += d[l + 1][r - 1][z][h][t][x];
								norm(f[l][r][i][j]);
							}
						}
					}
				}
			}
		}
	}
}

void calcd(int l, int r){
	if(usedd[l][r]){
		return;
	}
	usedd[l][r] = true;
	vector <pii> v;
	int i = l;
	while(i <= r){
		calcf(i, next[i]);
		v.pb(mp(i, next[i]));
		i = next[i] + 1;
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			d[l][r][i][j][i][j] = f[v[0].first][v[0].second][i][j];
		}
	}
	for(int i = 0; i < (int)v.size() - 1; i++){
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int h = 0; h < 2; h++){
					for(int t = 0; t < 2; t++){
						nd[j][z][h][t] = 0;
					}
				}
			}
		}
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int h = 0; h < 2; h++){
					for(int t = 0; t < 2; t++){
						for(int x = 0; x < 2; x++){
							for(int y = 0; y < 2; y++){
								if(check1(h, t, x, y)){
									nd[j][z][x][y] += (d[l][r][j][z][h][t] * f[v[i + 1].first][v[i + 1].second][x][y]) % MOD;
									norm(nd[j][z][x][y]);
								}
							}
						}
					}
				}
			}
		}
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int h = 0; h < 2; h++){
					for(int t = 0; t < 2; t++){
						d[l][r][j][z][h][t] = nd[j][z][h][t];
					}
				}
			}
		}
	}
}

int main(){
	//freopen("border.in", "r", stdin);
	//freopen("border.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int n = strlen(s), k = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			stack[k++] = i;
			continue;
		}
		next[stack[--k]] = i;
	}
	calcd(0, n - 1);
	ll ans = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int z = 0; z < 2; z++){
				for(int h = 0; h < 2; h++){
					ans += d[0][n - 1][i][j][z][h];
					norm(ans);
				}
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}