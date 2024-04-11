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

int n , m;
void work() {
    cin >> n >> m;
    while (m) {
        int x = m % n;
        if (x <= 1) {
            m /= n;
        } else {
            if (x + 1 != n) {
                puts("NO");
                return;
            }
            m /= n;
            ++ m;
        }
    }
    puts("YES");
}

int main() {
    work();
    return 0;
}