#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

string A = "RGBYW";

int main()
{
	vector<string> a;
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		a.pb(s);
	}
	int S = 10;
	for (int i = 0; i < (1<<10); i ++) {
		if (pct(i) >= S) continue;
		set<char> r;
		for (int j = 0; j < 5; j ++) 
			if ((i>>j)&1) r.insert(A[j]);
		for (int j = 0; j < 5; j ++) 
			if ((i>>(j+5))&1) r.insert('1'+j);
		bool F = 1;
		for (int j = 0; j < n; j ++) 
			for (int k = j+1; k < n; k ++) if (a[j] != a[k]) {
				if (a[j][0] != a[k][0] && (r.find(a[j][0]) != r.end() || r.find(a[k][0]) != r.end())) continue;
				if (a[j][1] != a[k][1] && (r.find(a[j][1]) != r.end() || r.find(a[k][1]) != r.end())) continue;
				F = 0;
			}
		if (F) S = pct(i);
	}
	cout << S << endl;
	return 0;
}