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

typedef unsigned int dword;
typedef unsigned char byte;
typedef dword ip;
const int SIZE = 100<<10;


int n, k;
ip arr[SIZE];

ip GetMask(int bits) {
	return ~((dword(1) << dword(32-bits)) - 1);
}

ip red[SIZE];
int GetNumber(int bits) {
	ip mask = GetMask(bits);
	for (int i = 0; i<n; i++)
		red[i] = arr[i] & mask;
	sort(red, red+n);
	int t = unique(red, red+n) - red;
	return t;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);

	for (int i = 0; i<n; i++) {
		dword bt[4];
		scanf("%u.%u.%u.%u", &bt[3], &bt[2], &bt[1], &bt[0]);
		arr[i] = (((((bt[3] << 8U) + bt[2]) << 8U) + bt[1]) << 8U) + bt[0];
//		printf("%08X\n", arr[i]);
	}

/*	for (int i = 1; i<=31; i++) {
		int t = GetNumber(i);
		printf("%d -> %d\n", i, t);
	}*/

	int left = 1 - 1;
	int right = 31;
	while (right - left > 1) {
		int middle = (left + right) >> 1;
/*		Eo(middle);
		Eo(GetNumber(middle));*/
		if (GetNumber(middle) < k)
			left = middle;
		else
			right = middle;
	}

	if (GetNumber(right) == k) {
		dword mask = GetMask(right);
		byte *bt = (byte*)(void*)&mask;
		printf("%u.%u.%u.%u\n", dword(bt[3]), dword(bt[2]), dword(bt[1]), dword(bt[0]));
	}
	else printf("-1\n");

	return 0;
}