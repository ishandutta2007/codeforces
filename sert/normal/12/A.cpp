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


string a, b, c;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> a >> b >> c;
    if (a[0] != c[2] || a[1] != c[1] || a[2] != c[0] || b[0] != b[2])
        fail();

    cout << "YES\n";

    return 0;
}