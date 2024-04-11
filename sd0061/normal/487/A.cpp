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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

int H , A , D;
int h , a , d;
int x , y , z;

void work() {
    int res = 1 << 30;
    cin >> H >> A >> D >> h >> a >> d >> x >> y >> z;
    for (int AA = A ; AA <= A + 200 ; ++ AA)
        for (int DD = D ; DD <= D + 100 ; ++ DD) {
            if (AA <= d) continue;
            int t = (h + AA - d - 1) / (AA - d);
            int HH = t * max(0 , a - DD) + 1;
            res = min(res , x * max(0 , HH - H) + y * (AA - A) + z * (DD - D));
        }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}