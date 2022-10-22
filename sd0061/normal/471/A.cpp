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
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 1000005;
int a[10];
void work() {
    int i , j , k;
    for (i = 1 ; i <= 6 ; ++ i)
        scanf("%d",&j) , ++ a[j];
    for (i = 1 ; i <= 9 ; ++ i) {
        if (a[i] >= 4) {
            a[i] -= 4;
            for (j = 1 ; j <= 9 ; ++ j) {
                if (a[j]) {
                    -- a[j];
                    for (k = j ; k <= 9 ; ++ k) {
                        if (a[k]) {
                            if (k == j)
                                puts("Elephant");
                            else
                                puts("Bear");
                            return;
                        }
                    }
                    ++ a[j];
                }
            }
            a[i] += 4;

        }
    }
    puts("Alien");
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}