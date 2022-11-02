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
bool u[10];
set<string> ans;
int M;
string w[256];

void go2(string s, int cnt, string res) {
	if (s.length() == 0 && cnt == 4) {
		res.erase(res.length()-1);
		ans.insert(res);
		return;
	}
	if (cnt == 4) return;
	int cur = 0;
	if (s[0] == '0') {
		go2(s.substr(1), cnt+1, res + w[0] + ".");
		return;
	}
	forn(i, 3) {
		if (s.length() == 0) return;
		cur = cur * 10 + s[0] - '0';
		s = s.substr(1);
		if (cur <= 255) {
			go2(s, cnt+1, res + w[cur] + ".");
		}
	}
}

void check(string s) {
	go2(s, 0, "");
}

void go(string s, int mask) {
	if (mask == M)
		check(s);
	if (s.length() + 2 > 12) return;
	forn(i, 10)
		if (u[i]) {
			string t = (char)(i + '0') + s + (char)(i + '0');	
			go(t, mask | (1 << i));
		}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(u, 0);
	cin >> n;
	M = 0;
	forn(i, n) {
		int x;
		cin >> x;
		u[x] = 1;
		M |= 1 << x;
	}
	if (n > 6) {
		cout << 0 << endl;
		return 0;
	}	
	forn(i, 256) {
		char buf[10];
		sprintf(buf, "%d", i);
		w[i] = buf;
	}
	go("", 0);
	forn(i, 10)
		if (u[i]) {
			string t = "";
			t += (char)i + '0';
			go(t, 1 << i);
		}
	cout << ans.size() << endl;
	for(set<string> :: iterator it = ans.begin(); it != ans.end(); it++)
		printf("%s\n", it->data());
	return 0;
}