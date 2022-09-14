#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <numeric>
#include <deque>
#include <queue>
typedef long long l;
typedef long double ld;
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    int ans;
    for (int i = 0; i < 10; i++) {
        if (a / (1 << i) == b / (1 << i)) {
            ans = i;
            break;
        }
    }
    if (1 << ans == n)
        cout << "Final!";
    else
        cout << ans;
}