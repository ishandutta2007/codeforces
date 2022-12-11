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

ll n, m;
char ch;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; cout << "\n", i++)
    for (int j = 0; j < m; j++) {
        cin >> ch;
        if (ch == '.') ch = ((i + j) % 2 ? 'B' : 'W');
        cout << ch;
    }

    return 0;
}