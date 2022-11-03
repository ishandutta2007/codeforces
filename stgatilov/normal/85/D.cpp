#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 100100;
const int BLOCK = 400;
const int CNT = (SIZE/BLOCK + 1);

int m;
int ct[SIZE], cx[SIZE];

int n;
map<int, int> ind;
int name[SIZE];

int cnt[CNT];
int64 sum[CNT][5];
int arr[CNT][BLOCK];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		char buff[256];
		scanf("%s", buff);
		if (strcmp(buff, "sum") == 0) ct[i] = 0;
		else {
			scanf("%d", &cx[i]);
			if (strcmp(buff, "add") == 0) ct[i] = 1;
			if (strcmp(buff, "del") == 0) ct[i] = -1;
		}
	}

	for (int i = 0; i<m; i++) if (ct[i]) ind[cx[i]] = 0;

	n = 0;
	for (map<int, int>::iterator it = ind.begin(); it != ind.end(); it++) {
		it->second = n;
		name[n] = it->first;
		n++;
	}

	for (int i = 0; i<m; i++) {
		if (ct[i] == 0) {
			int64 ans = 0;
			int s = 0;
			for (int u = 0; u<CNT; u++) {
				ans += sum[u][(1000000 + 2 - s) % 5];
				s += cnt[u];
			}
			printf("%I64d\n", ans);
		}
		else {
			int k = ind[cx[i]];

			int q = k / BLOCK;
			int r = k % BLOCK;

			if (ct[i] > 0) {
				int j;
				for (j = 0; j<cnt[q]; j++) if (arr[q][j] > k) break;
				for (int u = cnt[q]; u>j; u--) arr[q][u] = arr[q][u-1];
				arr[q][j] = k;
				cnt[q]++;
			}
			else {
				int j;
				for (j = 0; j<cnt[q]; j++) if (arr[q][j] == k) break;
				cnt[q]--;
				for (int u = j; u<cnt[q]; u++) arr[q][u] = arr[q][u+1];
			}

			memset(sum[q], 0, sizeof(sum[q]));
			for (int u = 0; u<cnt[q]; u++)
				sum[q][u % 5] += name[arr[q][u]];
		}
	}

	return 0;
}