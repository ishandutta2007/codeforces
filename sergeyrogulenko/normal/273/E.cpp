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

const int a[104][2] = 
{{1, 0},
{3, 1},
{4, 2},
{5, 1},
{7, 2},
{9, 0},
{13, 1},
{15, 2},
{19, 0},
{27, 1},
{39, 2},
{40, 0},
{57, 2},
{58, 1},
{81, 2},
{85, 0},
{120, 2},
{121, 1},
{174, 2},
{179, 0},
{255, 2},
{260, 1},
{363, 2},
{382, 0},
{537, 2},
{544, 1},
{780, 2},
{805, 0},
{1146, 2},
{1169, 1},
{1632, 2},
{1718, 0},
{2415, 2},
{2447, 1},
{3507, 2},
{3622, 0},
{5154, 2},
{5260, 1},
{7341, 2},
{7730, 0},
{10866, 2},
{11011, 1},
{15780, 2},
{16298, 0},
{23190, 2},
{23669, 1},
{33033, 2},
{34784, 0},
{48894, 2},
{49549, 1},
{71007, 2},
{73340, 0},
{104352, 2},
{106510, 1},
{148647, 2},
{156527, 0},
{220020, 2},
{222970, 1},
{319530, 2},
{330029, 0},
{469581, 2},
{479294, 1},
{668910, 2},
{704371, 0},
{990087, 2},
{1003364, 1},
{1437882, 2},
{1485130, 0},
{2113113, 2},
{2156822, 1},
{3010092, 2},
{3169669, 0},
{4455390, 2},
{4515137, 1},
{6470466, 2},
{6683084, 0},
{9509007, 2},
{9705698, 1},
{13545411, 2},
{14263510, 0},
{20049252, 2},
{20318116, 1},
{29117094, 2},
{30073877, 0},
{42790530, 2},
{43675640, 1},
{60954348, 2},
{64185794, 0},
{90221631, 2},
{91431521, 1},
{131026920, 2},
{135332446, 0},
{192557382, 2},
{196540379, 1},
{274294563, 2},
{288836072, 0},
{405997338, 2},
{411441844, 1},
{589621137, 2},
{608996006, 0},
{866508216, 2},
{884431705, 1},
{1234325532, 2},
{1299762323, 0}};


const int64 P = 1000000007;

int64 s[3];
int64 n, p;
int64 C[1050][1050];
int64 pw[3][1050];

int64 get(int64 l, int64 r) {
	if (l > p) return 0;
	r = min(r, p);
	l = p - l + 1;
	r = p - r + 1;
	swap(l, r);
	return ((l + r) * (r - l + 1) / 2) % P;	
}

int64 power(int64 a, int64 b) {
	int64 res = 1;
	a %= P;
	while (b) {
		if (b & 1)
			res = res * a % P;
		b >>= 1;
		a = a * a % P;
	}
	return res;
}

int main ()
{
	seta(C, 0);
	forn(i, 1050)
		C[i][0] = 1;
	for (int i = 1; i < 1050; i ++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
	cin >> n >> p;
	p--;
	int64 l = 1;
	for (int i = 1; i < 104; i++) {
		int64 r = a[i][0] - 1;
		s[a[i-1][1]] += get(l, r);
		l = r + 1;
	}
	forn(i, 3)
		s[i] %= P;
	forn(i, 3)
		pw[i][0] = 1;
	forn(i, 3)
		forn(j, 1050)
			if (j)
				pw[i][j] = pw[i][j-1] * s[i] % P;
	int64 res = 0;
	for (int z0 = 0; z0 <= n; z0++) 
		for (int z1 = 0; z1 + z0 <= n; z1++)
				if ((z1 & 1) || ((n-z0-z1) & 1))
					res += C[n][z0] * C[n-z0][z1] % P * pw[0][z0] % P * pw[1][z1] % P * pw[2][n-z0-z1] % P;
	res %= P;
	cout << res << endl;
	return 0;
}