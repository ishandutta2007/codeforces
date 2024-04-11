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
    char s[110], t[110] = "CODEFORCES";
    cin >> s;
    int n = strlen(s), m = strlen(t);
    int res = 0;
    for (int i = 0; i < n && i < m && s[i] == t[i]; ++i, ++res);
    for (int i = 0; i < n && i < m && s[n - 1 - i] == t[m - 1 - i]; ++i, ++res);
    cout << (res >= m ? "YES" : "NO") << endl;
    return 0;
}