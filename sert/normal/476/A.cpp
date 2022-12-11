#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

ll n, m, mx, mn;

int main() {
   // freopen("a.in", "r", stdin);
    cin >> n >> m;
    mn = (n + 1) / 2;
    mx = n;

    mn += m - 1;
    mn -= mn % m;

    printf("%d", (mn > mx ? -1 : mn));

    return 0;
}