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
    LL x , y;
    cin >> y >> x;
    map<int , int> cnt;
    for (int i = 0 ; i < 1 << 20 ; ++ i) {
        int j = i ^ (x & ((1 << 20) - 1));
        cnt[i + j] ++;
    }
    LL res = 0;
    for (int i = 0 ; i < 1 << 20 ; ++ i) {
        int j = i ^ (x >> 20);
        LL z = i + j; z <<= 20;
        if (z <= y) {
            LL d = y - z;
            if (d < 1 << 24 && cnt.count(d)) {
                res += cnt[d];
            }
        }
    }
    if (x == y)
        res -= 2;
    cout << res << endl;
    return 0;
}