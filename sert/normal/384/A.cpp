#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

void fail() {
    cout << "NO\n";
    exit(0);
}


int n, a[N], l, r, s[2], p;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n;
    cout << (n * n + 1) / 2 << "\n";

    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < n; j++)
            printf("%c", ((i + j) % 2 ? '.' : 'C'));

    return 0;
}