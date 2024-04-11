#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

void work() {
    int n , res = 0;
    cin >> n;
    while (n --) {
        int x1 , x2 , y1 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        res += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}