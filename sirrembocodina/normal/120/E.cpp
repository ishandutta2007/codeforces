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

int n, t;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << 1 - (n % 2) << endl;
	}

    return 0;
}