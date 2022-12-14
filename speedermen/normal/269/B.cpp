#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define sd second
#define fs first

#define inf 1000000000
#define nmax 100010
#define mmax 200010

int n, m;
int a[nmax], d[nmax];
double f[nmax];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] >> f[i];
	for(int i = 1; i <= n; ++i)
		d[a[i]] = (*max_element(d, d + a[i] + 1)) + 1;
	cout << n - (*max_element(d, d + n + 1)) << endl;
	//while(1);
}