#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, d, m;
int a[100500], b[100500], ans[100500];
int64 x;
int pos[100500];
int ones[100500];

int getNextX() {
    x = (x * 37LL + 10007LL) % 1000000007LL;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
        cin >> n >> d >> x;
        initAB();
        forn(i, n)
        	pos[a[i]] = i;
	m = 0;
	forn(i, n)
		if (b[i]) {
			ones[m] = i;
			m++;
		}
        int k = 200000000 / d;
        seta(ans, 0);
        ford(i, n) {
        	if (k == 0) break;
        	k--;
        	forn(j, d) {
        		if (ones[j] + pos[i] < n && ans[ones[j] + pos[i]] == 0) {
        			ans[ones[j] + pos[i]] = i + 1;
        		}
        	}
        }
        forn(i, n)
        	if (ans[i] == 0) {
        		for(int j = 0; j < d && ones[j] <= i; j++)
        			ans[i] = max(ans[i], a[i-ones[j]] + 1);
        	}
        forn(i, n)
        	printf("%d\n", ans[i]);
	return 0;
}