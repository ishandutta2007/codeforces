#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef double ld;
const ll N = 103;

int a[10][10], b[10][10];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
            b[i][j] = 1;
            cin >> a[i][j];
    }
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++)
    if (a[i][j] % 2 == 1) {
        b[i - 1][j] = 1 - b[i - 1][j];
        b[i + 1][j] = 1 - b[i + 1][j];
        b[i][j + 1] = 1 - b[i][j + 1];
        b[i][j - 1] = 1 - b[i][j - 1];
        b[i][j] = 1 - b[i][j];
    }
    fr(i, 3) {
        fr(j, 3)
            cout << b[i + 1][j + 1];
        cout << "\n";
    }
    return 0;
}