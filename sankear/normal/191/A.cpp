#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>

using namespace std;

//#define HOME
#define mp make_pair
#define pb push_back

typedef long long ll;

const int inf = (int)1e9;

int od[30];
int d[30][30];
char buf[100];

inline void relax(int &a, int b){
	a = max(a, b);
}

int main(){
#ifndef HOME
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			d[i][j] = -inf;
		}
	}
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		int len = strlen(buf);
		for(int j = 0; j < 26; j++){
			od[j] = d[j][buf[0] - 'a'] + len;
		}
		for(int j = 0; j < 26; j++){
			relax(d[j][buf[len - 1] - 'a'], od[j]);
		}
		relax(d[buf[0] - 'a'][buf[len - 1] - 'a'], len);
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		ans = max(ans, d[i][i]);
	}
	printf("%d\n", ans);
	return 0;
}