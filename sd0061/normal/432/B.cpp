#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;

#define N 100005
int n , X[N] , Y[N];
int cntx[N] , cnty[N];

void work() {
    int i , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&X[i] , &Y[i]);
        ++ cntx[X[i]] , ++ cnty[Y[i]];
    }
    for (i = 0 ; i < n ; ++ i) {
        x = n - 1;
        y = 0;
        x += cntx[Y[i]];
        y += n - 1 - cntx[Y[i]];
        printf("%d %d\n" , x , y);
    }

}

int main() {
    work();
    return 0;
}