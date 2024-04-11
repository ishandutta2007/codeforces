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
const int N = 1000005;

int n , x;
LL f[N];

int main() {
    int i , x; LL f = 0;
    scanf("%d",&n);
    LL res = 0 , f1 = -1LL << 60 , f2 = -1LL << 60;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        f1 = max(f1 , f - x);
        f2 = max(f2 , f + x);
        f = max(f1 + x , f2 - x);
        res = max(res , f);
    }
    cout << res << endl;
    return 0;
}