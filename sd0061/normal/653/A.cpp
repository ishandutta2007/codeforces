#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;

int n , a[N];

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            if (i == j) continue;
            for (int k = 0 ; k < n ; ++ k) {
                if (k == i || k == j)
                    continue;
                if (a[j] == a[i] + 1 && a[k] == a[i] + 2) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}