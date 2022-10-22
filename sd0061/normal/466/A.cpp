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
const int N = 100005;

void work() {
    int n , m , a , b;
    int res = 1 << 30;
    cin >> n >> m >> a >> b;
    for (int i = 0 ; i * m <= n + m ; ++ i)
        res = min(res , i * b + max(0 , n - i * m) * a);
    cout << res << endl;
}

int main() {
    work();
    return 0;
}