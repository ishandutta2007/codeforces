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
#include <bitset>
#include <sstream>
#include <queue>

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
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 900;

char res[nmax][nmax];

int calc(string s) {
	int res = 0, now = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '[') now ++;
		if (s[i] == ']') now --;
		res = max(res, now);
	}
	return res;
}

vector<string> split(string s) {
	int now = 0;
	vector<string> res;
	string q;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '[') now ++;
		if (s[i] == ']') now --;
		q += s[i];
		if (now == 0) {
			res.push_back(q);
			q = "";
		}
	}
	return res;
}


int gen(string s, int dep, int x, int y) {
	if (s.size() == 0) return y + 3;
	vector<string> e = split(s);
	if (e.size() > 1) {
		for (int i = 0; i < e.size(); i++)
			y = gen(e[i], dep, x, y);
		return y;
	} else {
		{
			res[x][y] = res[x + 2*dep][y] = '+';
			res[x][y+1] = res[x + 2*dep][y+1] = '-';
			for (int i = 1; i < dep * 2; i ++)
				res[x + i][y] = '|';
		}
		y = gen(s.substr(1, s.size() - 2), dep - 1, x + 1, y + 1);
		{
			res[x][y] = res[x + 2 * dep][y] = '+';
			res[x][y-1] = res[x + 2 * dep][y-1] = '-';
			for (int i = 1; i < dep * 2; i ++)
				res[x + i][y] = '|';
		}
		return y + 1;
	}	
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);

	int hm;
	string s;
	cin >> hm >> s;
	memset(res, 0, sizeof res);
	int n = 2 * calc(s) + 1;
	int m = gen(s, calc(s), 0, 0);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (res[i][j] == 0) res[i][j] = ' ';
			printf("%c", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}