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
using namespace std;
typedef long long LL;
const int N = 1005;

int main() {
    int n , m;
    cin >> n >> m;
    int L = (n + 1) / 2;
    if ((L + m - 1) / m * m > n)
        puts("-1");
    else
        cout << (L + m - 1) / m * m << endl;
    return 0;
}