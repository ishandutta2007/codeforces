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
int n , a[N];

void work() {
    int x , y , ans = 0;
    cin >> n;
    while (n --) {
        cin >> x >> y;
        if (x + 2 <= y)
            ++ ans;
    }
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}