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

string s;
int a[N][3], l, r, k[3], n;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        a[i + 1][0] = a[i][0];
        a[i + 1][1] = a[i][1];
        a[i + 1][2] = a[i][2];
        a[i + 1][s[i] - 'x']++;
    }
    cin >> n;
    while (n--) {
        cin >> l >> r;
        if (r - l < 2) {printf("YES\n"); continue;}
        k[2] = a[r][2] - a[l - 1][2];
        k[1] = a[r][1] - a[l - 1][1];
        k[0] = a[r][0] - a[l - 1][0];
        sort(k, k + 3);
        if (k[2] > k[0] + 1) printf("NO\n"); else printf("YES\n");
    }
    return 0;
}