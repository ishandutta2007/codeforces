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

int n;
char a[1000][1000];
bool fail;
pair <int, int> ans[10000];
int len;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n && !fail; i++) for (int j = 0; j < n && !fail; j++) {
        if (a[i][j] == '.') {ans[len++] = make_pair(i + 1, j + 1); break;}
        if (j == n - 1) fail = true;
    }
    if (fail) {
        fail = false;
        len = 0;
        for (int i = 0; i < n && !fail; i++) for (int j = 0; j < n && !fail; j++) {
        if (a[j][i] == '.') {ans[len++] = make_pair(j + 1, i + 1); break;}
        if (j == n - 1) fail = true;
    }
    }
    if (fail) cout << "-1";
    else for (int i = 0; i < len; i++) cout << ans[i].ff << " " << ans[i].ss << "\n";
    return 0;
}