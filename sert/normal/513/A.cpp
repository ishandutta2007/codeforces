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
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m >> t >> k;

    if (n > m) cout << "First\n";
    else cout << "Second\n";

    return 0;
}