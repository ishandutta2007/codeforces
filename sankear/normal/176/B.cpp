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

int n;
char s[1010], t[1010];
ll a[1010], b[1010], c[1010];

inline void norm(ll &a){
	while(a >= MOD){
		a -= MOD;
	}
}

inline int calc(int a, int b){
	if(a < b){
		return b - a;
	}
	int res = n - a + b;
	while(res >= n){
		res -= n;
	}
	return res;
}

void calc(int k){
	if(k == 0){
		for(int i = 0; i < n; i++){
			b[i] = a[i];
		}
		return;
	}
	if(k % 2 == 0){
		calc(k / 2);
		for(int i = 0; i < n; i++){
			c[i] = 0;
			int pos = i;
			for(int j = 0; j < n; j++){
				pos--;
				if(pos < 0){
					pos = n - 1;
				}
				c[i] = (c[i] + b[pos] * b[calc(pos, i)]) % MOD;
			}
		}
		for(int i = 0; i < n; i++){
			b[i] = c[i];
		}
		return;
	}
	calc(k - 1);
	for(int i = 0; i < n; i++){
		c[i] = 0;
		int pos = i;
		for(int j = 0; j < n - 1; j++){
			pos--;
			if(pos < 0){
				pos = n - 1;
			}
			c[i] += b[pos];
			norm(c[i]);
		}
	}
	for(int i = 0; i < n; i++){
		b[i] = c[i];
	}
}

int main(){
	//freopen("chart.in", "r", stdin);
	//freopen("chart.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%s %s %d", s, t, &k);
	n = strlen(s);
	a[0] = 1;
	calc(k);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		bool fl = true;
		int pos = i;
		for(int j = 0; j < n; j++){
			if(s[pos++] != t[j]){
				fl = false;
				break;
			}
			if(pos >= n){
				pos = 0;
			}
		}
		if(fl){
			ans += b[i];
			norm(ans);
		}
	}
	cout << ans << endl;
	return 0;
}