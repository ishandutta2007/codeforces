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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

string s1, s2;
char buf[2000000];
int next[10000][26];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%s", buf);
	s1 = buf;
	scanf ("%s", buf);
	s2 = buf;
	int n = s1.length();
	seta (next, 255);
	forn (j, 26) 
		if (s1.find ('a' + j) != -1) {
			int p = 0;
			char c = j + 'a';
			forn (i, n) {
				if (i == p) 
					p = (p + 1) % n;
				while (s1[p] != c) 
					p = (p + 1) % n;
				next[i][j] = p;
			}
		}
	int res = 0;
	int p = n-1;
	forn (i, s2.length()) {
		char c = s2[i] - 'a';
		if (next[p][c] == -1) {
			cout << -1 << endl;
			return 0;
		}
		if (next[p][c] <= p)
			res ++;
		p = next[p][c];
	}
	cout << res << endl;
	return 0;
}