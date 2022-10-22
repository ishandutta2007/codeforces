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
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 2005;
LL n;

void work() {
    int i , res = 0;
    cin >> n;
    for (i = 1 ; i <= 2000000 ; ++ i) {
        LL m = n + i;
        if (m % 3)
            continue;
        m /= 3;
        LL p = (LL)(i + 1) * i / 2;
        if (m >= p)
            ++ res;
    }
    cout << res << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}