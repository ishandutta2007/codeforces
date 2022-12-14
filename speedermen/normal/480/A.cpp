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
#define mmax 150010
#define eps 1e-9

pair < int, int > p[nmax];
int n, dp[nmax];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	//ios :: sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &p[i].fs, &p[i].sd);
	sort(p + 1, p + n + 1);
	dp[1] = min(p[1].fs, p[1].sd);
	for(int i = 2; i <= n; ++i) {
		if(p[i].sd >= dp[i - 1])
			dp[i] = min(p[i].sd, p[i].fs);
		else
			dp[i] = p[i].fs;
	}
	cout << dp[n] << endl;
	getchar(); getchar();
	return 0;
}