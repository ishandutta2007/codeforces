//#pragma comment(linker, "/STACK:20000000")
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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 2<<10;
const int MAXV = 1<<17;

int n;
int arr[SIZE];
vector<int> elems[MAXV];

int fenw[SIZE];

inline int h(int x) { return ((x ^ (x+1)) + 1) >> 1; }

void Add(int x, int add) {
	for (int i = x; i<SIZE; i += h(i))
		fenw[i] += add;
}

int GetSum(int cnt) {
	int res = 0;
	for (int i = cnt-1; i>=0; i -= h(i))
		res += fenw[i];
	return res;
}

int res[SIZE][SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &arr[i]);
		arr[i] = abs(arr[i]);
	}

	for (int i = 0; i<n; i++)
		elems[arr[i]].push_back(i);

	int ans = 0;
	for (int k = 0; k<MAXV; k++) {
		const auto& v = elems[k];
		if (v.empty()) continue;
		int s = v.size();

		int tans = 1000000000;

		for (int i = 0; i<=s; i++)
			for (int j = 0; j<=s; j++)
				res[i][j] = 1000000000;
		res[0][0] = 0;
		for (int i = 0; i<s; i++)
			for (int j = 0; j<=i; j++) {
				int tres = res[i][j];
				if (tres >= 1000000000) continue;

				int kleft = GetSum(v[i]+1);
				int kright = GetSum(n) - kleft;
				res[i+1][j] = min(res[i+1][j], tres + (k==0 ? 0 : j) + kleft);
				res[i+1][j+1] = min(res[i+1][j+1], tres + kright);
			}
		for (int j = 0; j<=s; j++) tans = min(tans, res[s][j]);

		Eo(k);
		Eo(tans);

		ans += tans;

		for (int i = 0; i<v.size(); i++)
			Add(v[i], 1);
	}

	printf("%d\n", ans);
	             
	return 0;
}