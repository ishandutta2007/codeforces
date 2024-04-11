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

int n, k;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	//ios :: sync_with_stdio(false);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n - k; ++i)
		cout << i + 1 << " ";
	int last = n, cur = n - k + 1;
	for(int i = n - k; i < n; ++i)
		if(i % 2 != (n - k) % 2)
			cout << cur++ << " ";
		else
			cout << last-- << " ";
	getchar(); getchar();
	return 0;
}