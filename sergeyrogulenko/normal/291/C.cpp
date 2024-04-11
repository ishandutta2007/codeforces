#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int64 a[100500];
int n, k;

int64 read() {
	int64 a1, a2, a3, a4;
	scanf("%I64d.%I64d.%I64d.%I64d", &a1, &a2, &a3, &a4);
	return (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
}

void print(int64 mask) {
	cout << (mask >> 24) << "." << ((mask >> 16) & (255)) << "." << ((mask >> 8) & (255)) << "." << (mask & (255)) << endl;
}

set<int64> S;

bool check(int64 mask) {
	S.clear();
	forn(i, n)
		S.insert(a[i] & mask);
	return I S.size() == k;			
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k;
	forn(i, n)
		a[i] = read();
	for (int i = 31; i >= 0; i--) {
		int64 mask = (1LL << 32) - (1LL << i);
		if (check(mask)) {
			print(mask);
			return 0;
		}
	}
	cout << -1 << endl;	
	return 0;
}