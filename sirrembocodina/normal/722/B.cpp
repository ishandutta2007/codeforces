#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
 
using namespace std;
 
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
 
const ld pi = 3.1415926535897932384626433832795l;
 
const ll mod = 1000000007;
 
int main() {
	int n, a[100];
	string s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		for (int j = 0; j < int(s.size()); ++j) {
			a[i] -= s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y';
		}
		if (a[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
    return 0;
}