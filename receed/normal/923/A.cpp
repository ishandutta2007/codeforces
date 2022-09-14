#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        if (a[i])
            continue;
        for (int j = i * 2; j <= n; j += i)
            a[j] = i;
    }
    int ans = n - a[n] + 1;
    for (int i = n - a[n] + 1; i < n; i++)
        if (a[i])
            ans = min(ans, i - a[i] + 1);
    cout << max(ans, 3);
}