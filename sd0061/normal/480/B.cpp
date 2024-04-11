#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 100005;
int n , L , X , Y;
int a[N];
set<int> hash;

int main() {
    int i ;
    bool fx = 0 , fy = 0;
    scanf("%d%d%d%d",&n,&L,&X,&Y);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&a[i]);
        if (hash.count(a[i] - X))
            fx = 1;
        if (hash.count(a[i] - Y))
            fy = 1;
        hash.insert(a[i]);
    }
    if (fx && fy) {
        puts("0");
    } else if (!fx && fy) {
        printf("1\n%d\n" , X);
    } else if (fx && !fy) {
        printf("1\n%d\n" , Y);
    } else {
        hash.clear();
        for (i = 0 ; i < n ; ++ i) {
            if (hash.count(a[i] - X - Y)) {
                printf("1\n%d\n" , a[i] - X);
                return 0;
            }
            if (hash.count(a[i] + X - Y)) {
                if (a[i] + X <= L) {
                    printf("1\n%d\n" , a[i] + X);
                    return 0;
                }
                if (a[i] - Y >= 0) {
                    printf("1\n%d\n" , a[i] - Y);
                    return 0;
                }
            }
            hash.insert(a[i]);
        }
        printf("2\n%d %d\n" , X , Y);
    }

    return 0;
}