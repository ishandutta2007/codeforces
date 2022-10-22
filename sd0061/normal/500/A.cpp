#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , K , a[N];
bool f[N];

int main() {
    scanf("%d%d",&n,&K);
    for (int i = 1 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    int x = 1;
    while (x < n) {
        f[x] = 1;
        x += a[x];
    }
    f[x] = 1;
    printf(f[K] ? "YES" : "NO");
    return 0;
}