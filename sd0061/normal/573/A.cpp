#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a[N];

int main() {
    int i , x = 0;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        x = __gcd(x , a[i]);
    }
    for (int i = 0 ; i < n ; ++ i) {
        int y = a[i] / x;
        while (y % 2 == 0)
            y /= 2;
        while (y % 3 == 0)
            y /= 3;
        if (y > 1) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}