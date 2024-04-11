#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 60

using namespace std;

const long long mod = 1000000007;
long long can[maxn][maxn];
long long tmp[maxn][maxn];
long long res[maxn][maxn];
long long f[maxn];

long long calc(long long n, int m){
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			res[i][j] = 0LL;
	for(int i = 1; i <= m; ++i)res[i][i] = 1LL;
	if(n == 1)return((long long) m);
	n -= 1;
	//if(n < 0)return((long long) m);
	while(n > 0){
		if(n % 2){
			--n;
			for(int i = 1; i <= m; ++i)
				for(int j = 1; j <= m; ++j){
					tmp[i][j] = 0;
					for(int k = 1; k <= m; ++k)
						tmp[i][j] = (tmp[i][j] + res[i][k] * can[k][j]) % mod;
				}
			for(int i = 1; i <= m; ++i)
				for(int j = 1; j <= m; ++j)
					res[i][j] = tmp[i][j];
		}
		n /= 2;
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= m; ++j){
				tmp[i][j] = 0;
				for(int k = 1; k <= m; ++k)
					tmp[i][j] = (tmp[i][j] + can[i][k] * can[k][j]) % mod;
			}
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= m; ++j)
				can[i][j] = tmp[i][j];
	}
	long long ans(0);
	//for(int i = 1; i <= m; ++i)f[i] = 1;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			ans = (ans + res[j][i]) % mod;
	return ans;
}

int get(char c){
	if(islower(c))return(int(c - 'a' + 1));
	return(int(c - 'A' + 27));
}

int main(){
	int m, k;
	long long n;
	cin >> n >> m >> k;
	memset(can, 0, sizeof(can));
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			can[i][j] = 1;
	for(int i = 1; i <= k; ++i){
		char a, b;
		scanf(" %c%c", &a, &b);
		//printf("a = %c, b = %c\n", a, b);
		can[get(a)][get(b)] = 0;
		//printf("a = %d, b = %d\n", get(a), get(b));
	}
	long long rr = calc(n, m);
	cout << rr << '\n';
	return 0;
}