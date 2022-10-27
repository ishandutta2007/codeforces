#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 100000 + 10;
int a[10], n;
int main() {
    for (int i = 0; i < 4; i ++) {
        scanf("%d", &a[i]); n += a[i];
    }
    if ( abs(a[0] + a[2] - a[1] - a[3]) > 1 ) {
        return !printf("NO\n");
    }

    int now = 0;
    if (a[0] + a[2] >= a[1] + a[3]) {
        if (a[0]) now = 0; else now = 2;
    } else {
        if (a[1]) now = 1; else now = 3;
    }

    vector<int> ans;
    ans.push_back(now);
    a[now] --;
    for (int i = 2; i <= n; i ++) {
        if (now >= 1 && a[ now - 1 ]) {
            now = now - 1; 
            if (a[now] == 0) return !printf("NO\n");
            a[now] --; ans.push_back(now);
        } else {
            now = now + 1; 
            if (a[now] == 0) return !printf("NO\n");
            a[now] --; ans.push_back(now);
        }
    }
    printf("YES\n");
    for (auto x: ans) {
        printf("%d ", x);
    }
}