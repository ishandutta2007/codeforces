#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int k;
	cin >> k;
	k--;
	vector<int> a(n);
	forn (i, n) {
		cin >> a[i];
	}
	for (; a[k] == 0; k = (k + 1) % n);
	cout << k + 1;
    return 0;
}