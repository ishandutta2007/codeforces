#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int cc = 70;
const int nn = cc * 2;
const int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};

int cnt[cc * 2][cc * 2];

int aa(int x) {
	return x < 0 ? -x : x;
}

int main() {
	int n;
	scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));

		cnt[cc][cc] = n;

		bool flag = true;
		while (flag) {
			flag = false;
			forn(i, nn)
				forn(j, nn)
					if (cnt[i][j] > 3) {
						int c2 = cnt[i][j] >> 2;
						forn(w, 4)
							cnt[i+di[w]][j+dj[w]] += c2;
						cnt[i][j] &= 3;
						flag = true;
					}
		}


	int t, x, y;
	scanf("%d", &t);
	forn(q, t) {
		scanf("%d %d", &x, &y);
		if (aa(x) > cc - 2 || aa(y) > cc - 2)
			printf("0\n");
		else
			printf("%d\n", cnt[cc + x][cc + y]);
	}
	return 0;
}