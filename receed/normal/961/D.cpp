#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
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

const int N = 100002;
ll x[N], y[N];
int n;


bool onl(int a, int b, int c) {
    return (x[b] - x[a]) * (y[c] - y[a]) == (x[c] - x[a]) * (y[b] - y[a]);
}

bool check(int a, int b) {
    int c = -1, d = -1;
    for (int i = 0; i < n; i++) {
        if (onl(a, b, i)) {
            continue;
        }
        if (c < 0) {
            c = i;
        }
        else if (d < 0) {
            d = i;
        }
        else if (!onl(c, d, i)) {
            return 0;
        }
    }
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];      
    if (n <= 4 || check(0, 1) || check(0, 2) || check(1, 2))
        cout << "YES";
    else
        cout << "NO";
}