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
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int main() {
    int n , k;
    cin >> n >> k;
    if (n & 1) {
        if (k >= n / 2)
            cout << (LL)n * (n - 1) / 2 << endl;
        else {
            LL res = 0;
            for (int i = 0 ; i < k ; ++ i) {
                n -= 2;
                res += n + n + 1;
            }
            cout << res << endl;
        }
    } else {
        if (k >= (n + 1) / 2)
            cout << (LL)n * (n - 1) / 2 << endl;
        else {
            LL res = 0;
            for (int i = 0 ; i < k ; ++ i) {
                n -= 2;
                res += n + n + 1;
            }
            cout << res << endl;
        }
    }
    return 0;
}