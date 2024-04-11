#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 131072;

void work() {
    LL n , m;
    cin >> n >> m;
    LL x = n / m , y = n % m;
    LL mn = y * (x + 1) * x / 2 + (m - y) * (x - 1) * x / 2;
    LL mx = (n - m + 1) * (n - m) / 2;
    cout << mn << ' ' << mx << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}