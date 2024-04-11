#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
const long long N = 1e5 + 34;
typedef long long ll;
ll n, h, ans;
int main() {
    // freopen("a.in", "r", stdin);
    //  freopen("a.out", "w", stdout);
    cin >> n;
    h = 3 - n % 3;
    while (3 * h * (h + 1) / 2 - h <= n) {
        h += 3;
        ans++;
    }
    cout << ans;
}