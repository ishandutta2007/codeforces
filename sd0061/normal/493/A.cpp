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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;

char S[N] , T[N];
int A[N] , B[N];
int n;
void work() {
    int i , x , t;
    char a[10] , b[10];
    scanf("%s%s" , S , T);
    scanf("%d" , &n);
    while (n --) {
        scanf("%d%s%d%s" , &t , a , &x , b);
        i = *b == 'r' ? 2 : 1;
        if (*a == 'h') {
            A[x] += i;
            if (A[x] >= 2) {
                printf("%s %d %d\n" , S , x , t) , A[x] = -1 << 30;
            }
        } else {
            B[x] += i;
            if (B[x] >= 2)
                printf("%s %d %d\n" , T , x , t) , B[x] = -1 << 30;
        }
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}