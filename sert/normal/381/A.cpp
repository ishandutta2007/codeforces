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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    l = 0;
    r = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[l] > a[r])
            s[p] += a[l++];
        else
            s[p] += a[r--];
        p = 1 - p;
    }

    cout << s[0] << " " << s[1] << "\n";

    return 0;
}