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
#define mmax 20010
#define eps 1e-9

int n, k;
vector < int > v;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("tree.in", "r", stdin); freopen("tree.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int cur = 1;
	for(int i = 0; i < n; ++i) {
		v.pb(cur); v.pb(cur + 1); v.pb(cur + 2); v.pb(cur + 4);
		cur += 6;
	}
	cout << v.back() * k << endl;
	for(int i = 0; i < n; ++i) {
		for(int j = 4 * i; j < 4 * i + 4; ++j) {
			cout << v[j] * k << " ";
		}
		cout << endl;
	}
	cin.get(); cin.get();
	return 0;
}