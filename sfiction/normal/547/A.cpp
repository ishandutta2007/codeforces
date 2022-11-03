#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <utility>
#include <vector>

#define debug(x) cout << #x##" = " << x;

using namespace std;

const int MAXN = 1E6 + 10;

int m;
int lenf, leng;
int cntf, cntg;
int f[MAXN], g[MAXN];

void water(int (&f)[MAXN], int &len, int &cnt, int h, int x, int y){
	memset(f, -1, sizeof(f));
	cnt = 0;
	do{
//		printf("%d %d\n", h, cnt);
		f[h] = cnt++;
		h = (x * (long long)h + y) % m;
	}while (!~f[h]);
	len = cnt - f[h];
	cnt = f[h];
//	printf("%d\n", len);
}

int main(){
	int h1, a1, x1, y1;
	int h2, a2, x2, y2;

	scanf("%d", &m);
	scanf("%d%d", &h1, &a1);
	scanf("%d%d", &x1, &y1);
	water(f, lenf, cntf, h1, x1, y1);
	scanf("%d%d", &h2, &a2);
	scanf("%d%d", &x2, &y2);
	water(g, leng, cntg, h2, x2, y2);

	if (~f[a1] && ~g[a2]){
//		printf("%d %d\n%d %d\n", cntf, cntg, f[a1], g[a2]);
		if (f[a1] < cntf && f[a2] < cntg){
			if (f[a1] == f[a2])
				printf("%d\n", f[a1]);
			else
				puts("-1");
		}
		else if (f[a1] < cntf){
			if (f[a1] >= g[a2] && (f[a1] - g[a2]) % leng == 0)
				printf("%d\n", f[a1]);
			else
				puts("-1");
		}
		else if (g[a2] < cntg){
			if (g[a2] >= f[a1] && (g[a2] - f[a1]) % lenf == 0)
				printf("%d\n", g[a2]);
			else
				puts("-1");
		}
		else{
			int i;
			for (i=0;i<2*MAXN;++i){
				long long t = f[a1] + (long long)i * lenf;
				if (t >= g[a2] && (t - g[a2]) % leng == 0){
					printf("%I64d\n", t);
					break;
				}
			}
			if (i == 2 * MAXN)
				puts("-1");
		}
	}
	else
		puts("-1");

	return 0;
}