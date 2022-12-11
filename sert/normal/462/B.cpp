#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

long long ans, n, k, a[100];
char ch;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;
    while (n--) {
        cin >> ch;
        a[ch - 'A']++;
    }
    sort(a, a + 26);

    for (int i = 25; i >= 0 && k >= 0; i--) {
        if (a[i] >= k) {
            ans += k * k;
            k = 0;
        } else {
            ans += a[i] * a[i];
            k -= a[i];
        }
    }

    cout << ans;

    return 0;
}