#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 1700;
int n, k;
int res[nmax];
string s[nmax];


string gen(int k) {
	string res = "Aa";
	res[0] += k / 26;
	res[1] += k % 26;
	return res;
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n >> k;
	for (int i = 0; i < n - k + 1; i ++)
		cin >> s[i];

	for (int i = 0; i < n; i ++)
		res[i] = -1;

	int last = -1;
	for (int i = 0; i < n; i ++)
		if (s[i] == "YES") {
			if (last == -1 || last + k - 1 < i) {
				int st = 0;
				if (last == -1) {
					for (int j = 0; j < k; j ++)
						res[i+j] = j;
				} else
					res[i + k - 1] = res[last];
				last = i;
				continue;
			}
			for (int j = last; j < i; j ++)
				res[i + k - 1 - (j - last)] = res[j];
			last = i;
		} else {
			if (last != -1) 
				res[i + k - 1] = res[i];
			else
				res[i] = 0;
		}


	for (int i = 0; i < n; i ++)
		cout << gen(res[i]) << " ";
	cout << endl;
	return 0;
}