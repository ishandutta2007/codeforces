#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
const long long N = 1e5 + 34;
typedef long long ll;
ll n, a, b, x;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> a >> b;
    while (n --> 0) {
        cin >> x;
        cout << ((a * x) % b) / a << " ";
    }
}