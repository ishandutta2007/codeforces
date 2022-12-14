#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 100010
#define mmax 100010
#define eps 1e-9

int n, k, all;
int f[nmax], ok[nmax];
pair < pair < string, string >, int > s[nmax];
string cur[nmax];

bool cmp(const pair < pair < string, string >, int > & a, const pair < pair < string, string >, int > b) {
	return a.fs.fs < b.fs.fs;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i].fs.fs >> s[i].fs.sd;
		s[i].sd = i;
	}
	for(int i = 1; i <= n; ++i)
		cin >> f[i];
	//sort(s + 1, s + n + 1, cmp);
	bool ok = true;
	cur[1] = min(s[f[1]].fs.fs, s[f[1]].fs.sd);
	for(int i = 2; i <= n; ++i) {
		if(min(s[f[i]].fs.fs, s[f[i]].fs.sd) > cur[i - 1])
			cur[i] = min(s[f[i]].fs.fs, s[f[i]].fs.sd);
		else if(max(s[f[i]].fs.fs, s[f[i]].fs.sd) > cur[i - 1])
			cur[i] = max(s[f[i]].fs.fs, s[f[i]].fs.sd);
		else
			ok = false;
	}
	puts(ok ? "YES" : "NO");
	cin.get(); cin.get();
	return 0;
}