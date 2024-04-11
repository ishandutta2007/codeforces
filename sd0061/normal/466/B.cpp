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
    LL n , a , b;
    cin >> n >> a >> b;
    if (a * b >= 6 * n) {
        cout << a * b << endl << a << ' ' << b << endl;
    } else {
        bool flag = a > b;
        if (a > b) swap(a , b);
        pair<LL , LL> res(1LL << 60 , 1);
        for (LL i = 0 ; (a + i) * (a + i) <= 6 * n ; ++ i) {
            LL j = (6 * n + a + i - 1) / (a + i);
            if (j >= b)
                res = min(res , make_pair((a + i) * j , (a + i)));
        }
        cout << res.first << endl;
        if (flag)
            res.second = res.first / res.second;
        cout << res.second << ' ' << res.first / res.second << endl;
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}