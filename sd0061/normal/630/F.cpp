#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 100005;

int main() {
    LL n;
    cin >> n;
    LL res = 0;
    for (int j = 5 ; j <= 7 ; ++ j) {
        LL x = 1;
        for (int i = 1 ; i <= j ; ++ i) {
            x = x * (n - i + 1) / i;
        }
        res += x;
    }
    cout << res << endl;
    return 0;
}