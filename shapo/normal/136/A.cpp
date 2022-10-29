#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

#define maxn 110

using namespace std;

int n, p[maxn], pr[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &p[i]);
        pr[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", pr[i]);
    printf("\n");
    return 0;
}