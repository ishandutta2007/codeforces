#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const double INF = 1e12+7;
const int N = 200000 + 10;
int n;
int a[N], suf[N];
typedef pair<int, int> pii;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) { 
        scanf("%d", &a[i]);
        suf[i] = -1e9;
    }
    suf[n+1] = -1e9 + 7;
    for (int i = n; i >= 1; i --) {
        suf[i] = max(suf[i+1], a[i]-i);
    }
    int cur = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i ++) {
        //printf("%d %d\n", i, suf[i]);
        if (cur - i < suf[i]) {
            cur ++;
        }
        //printf("%d\n", cur);
        sum += cur;
    }
    for (int i = 1; i <= n; i ++) {
        sum -= (a[i]);
    }
    printf("%lld\n", sum);
}