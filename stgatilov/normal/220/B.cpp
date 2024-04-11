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

const int SIZE = 100<<10;

int n, m;
int arr[SIZE];
int mjsum[SIZE][512];
int freq[SIZE];
vector<int> major;

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

	for (int i = 0; i<n; i++) if (arr[i] <= n) freq[arr[i]]++;
	for (int i = 1; i<=n; i++) if (freq[i] >= i)
		major.push_back(i);

	for (int i = 0; i<major.size(); i++) {
		mjsum[0][i] = 0;
		for (int j = 0; j<n; j++)
			mjsum[j+1][i] = mjsum[j][i] + (arr[j] == major[i]);
	}

	for (int i = 0; i<m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;

		int res = 0;
		for (int j = 0; j < major.size(); j++) {
			int x = major[j];
			res += (mjsum[r][j] - mjsum[l][j] == x);
		}

		printf("%d\n", res);
	}



	return 0;
}