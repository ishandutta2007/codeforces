#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

string s[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string k;
ll n;
ll a[N], b[N];
bool fail;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < 8; i++) {
        fail = false;
        if (s[i].length() != n) continue;
        for (int j = 0; j < n; j++)
            if (s[i][j] != k[j] && k[j] != '.')
                fail = true;
        if (!fail) {
            cout << s[i];
            return 0;
        }
    }
    return 0;
}