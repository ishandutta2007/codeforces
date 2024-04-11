#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , m;
int a[N];
void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    sort(a , a + n);
    for (int i = 0 ; i < m ; ++ i) {
        int x;
        scanf("%d" , &x);
        printf("%d%c" , (int)(upper_bound(a , a + n , x) - a) , " \n"[i + 1 == m]);
    }
}

int main() {
    work();
    return 0;
}