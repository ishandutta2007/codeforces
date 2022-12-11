#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int n, m;
string s, k;

int d[500][500];
bool a1, a2, b1, b2;
bool v[500], g[500];
bool u[500][500];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    cin >> s >> k;

    if (s[0] == '>' && s[n - 1] == '<' && k[0] == '^' && k[m - 1] == 'v') {cout << "YES\n"; return 0;}
    if (s[0] == '<' && s[n - 1] == '>' && k[0] == 'v' && k[m - 1] == '^') {cout << "YES\n"; return 0;}
    cout << "NO\n";

    return 0;
}