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

const ll hx = (ll)(2e5 + 3);

int n;
char s[1000100], t[1000100];
char ss[2000200];
int pref[2000200];
ll p[1000100], hs[1000100], hsrev[1000100], ht[1000100];

inline bool check(int i, int j, int z, int h){
	ll h1 = (hs[j] - (i > 0 ? hs[i - 1] : 0)) * p[n - i];
	ll h2 = (ht[h] - (z > 0 ? ht[z - 1] : 0)) * p[n - z];
	return h1 == h2;
}

inline bool checkrev(int i, int j, int z, int h){
	ll h1 = (hsrev[i] - (j < n - 1 ? hsrev[j + 1] : 0)) * p[j + 1];
	ll h2 = (ht[h] - (z > 0 ? ht[z - 1] : 0)) * p[n - z];
	return h1 == h2;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  gets(s);
	gets(t);
	n = strlen(s);
	int m = strlen(t);
	if(n != m){
		printf("-1 -1\n");
		return 0;
	}
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] * hx;
	}
	for(int i = 0; i < n; i++){
		hs[i] = (i > 0 ? hs[i - 1] : 0) + s[i] * p[i];
	}
	for(int i = n - 1; i >= 0; i--){
		hsrev[i] = (i < n - 1 ? hsrev[i + 1] : 0) + s[i] * p[n - i - 1];
	}
	for(int i = 0; i < n; i++){
		ht[i] = (i > 0 ? ht[i - 1] : 0) + t[i] * p[i];
	}
	m = 0;
	for(int i = n - 1; i >= 0; i--){
		ss[++m] = s[i];
	}
	ss[++m] = 127;
	for(int i = 0; i < n; i++){
		ss[++m] = t[i];
	}
	for(int i = 2; i <= m; i++){
		int j = pref[i - 1];
		while(j > 0 && ss[j + 1] != ss[i]){
			j = pref[j];
		}
		if(ss[j + 1] == ss[i]){
			pref[i] = j + 1;
		}
	}
	for(int i = n - 2; i >= 0; i--){
		if(checkrev(0, i, n - i - 1, n - 1)){
			int res = n - pref[n + n - i];
			if(check(i + 1, res - 1, 0, res - i - 2)){
				printf("%d %d\n", i, res);
				return 0;
			}
		}
	}
	printf("-1 -1\n");
	return 0;
}