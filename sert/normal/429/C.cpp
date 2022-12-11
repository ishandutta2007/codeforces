#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <ctime>

#define y1 yy1
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1003;

int n, h, len;
int c[N], sum[N], p[N];

void go(int v) {

    if (v == len - 1) {
        cout << "YES\n";
        exit(0);
    }

    for (int i = v + 1; i < len; i++) {
        p[v] = i;
        sum[i] += c[v];

        if (sum[i] < c[i] && c[i] > c[v] + 1)
            go(v + 1);

        sum[i] -= c[v];
    }
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (n == 1 && h == 1) {
            cout << "YES\n";
            return 0;
        }
        if (h == 2) {
            cout << "NO\n";
            return 0;
        }
        if (h != 1)
            c[len++] = h;
    }

    sort(c, c + len);
    if (c[len - 1] != n || len > 11) {
        cout << "NO\n";
        return 0;
    }

    if (n == 1) {
        cout << "YES\n";
        return 0;
    }

    go(0);

    cout << "NO\n";

    return 0;
}