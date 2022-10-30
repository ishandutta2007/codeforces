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

int n;                                                                                        
string ps[100500];
int p[100500];
string t;
char buf[300500];
int l[300500];
int next[300500][26];
int res;
vector<int> g[100500];

string read() {
	scanf("%s", buf);
	return buf;
}

void go(int v, int state) {
	string& s = ps[v];
	forn(i, s.length()) {
		state = next[state][I s[i]];
		if (state == I t.length()) res++;
	}
	forn(i, g[v].size())
		go(g[v][i], state);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		g[p[i]].pb(i);
		ps[i] = read();
		forn(j, ps[i].length())
			ps[i][j] -= 'a';
	}
	t = read();
	forn(i, t.length())
		t[i] -= 'a';
	l[0] = -1;
	for (int i = 1; i < (int)t.length(); i++) {
		l[i] = l[i-1];
		while (l[i] >= 0 && t[l[i] + 1] != t[i])
			l[i] = l[l[i]];
		if (t[l[i]+1] == t[i])
			l[i]++;
	}
	seta(next[0], 0);
	next[0][I t[0]] = 1;
	for (int i = 1; i < I t.length(); i++) {
		next[i][I t[i]] = i + 1;
		forn(j, 26)
			if (j != t[i])
				next[i][j] = next[l[i-1]+1][j];
	}
	forn(j, 26)
		next[t.length()][j] = next[l[I t.length()-1]+1][j];
	res = 0;
        go(0, 0);
        cout << res << endl;	
	return 0;
}