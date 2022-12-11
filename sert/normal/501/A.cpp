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
typedef long double ld;
const int N = 1e6 + 7;
const ll md = 1e9 + 7;

ll a, b, c, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> a >> b >> c >> d;

    a = max(75 * a, 250 * a - a * c);
    b = max(75 * b, 250 * b - b * d);

    if (a == b) cout << "Tie";
    else if (a < b) cout << "Vasya";
    else cout << "Misha";

    return 0;
}