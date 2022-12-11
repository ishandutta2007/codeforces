#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    int res = min(l, r);
    l -= res;
    r -= res;
    res *= 2;
    l = max(r, l);
    r = min(l, a);
    res += 2 * r;
    l -= r;
    a -= r;
    res += a - (a % 2);
    cout << res;
    return 0;
}