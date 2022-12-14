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
#define nmax 1000010
#define mmax 100010
#define eps 1e-9

bool pr[nmax];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	int n; cin >> n;
	for(int i = 2; i <= n; ++i)
		if(!pr[i]) {
			for(int j = 2 * i; j <= n; j += i)
				pr[j] = 1;
		}
	for(int i = 2; i <= n; ++i)
		if(pr[i] && pr[n - i]) {
			cout << i << " " << n - i << endl;
			break;
		}
	cin.get(); cin.get();
	return 0;
}