#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
int n , K , a[N] , num[N] , cnt;

void work() {
    scanf("%d%d" , &n , &K);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    int res = -1 << 30 , E;

    for (int i = 0 , j = -1 ; i < n ; ++ i) {
        if (++ num[a[i]] == 1)
            ++ cnt;
        while (cnt > K) {
            ++ j;
            if (-- num[a[j]] == 0)
                -- cnt;
        }
        if (i - j > res) {
            res = i - j;
            E = i;
        }        
    }
    printf("%d %d\n" , E - res + 2 , E + 1);
}

int main() {
    work();
    return 0;
}