#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <functional>

#define pi M_PI
#define maxn 400

using namespace std;

int n;
int ttm[maxn];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &ttm[i]);
    int max_s = 710, cur = 0, ctm = 0;
    sort(ttm, ttm + n);
    int i = 0;
    while (i < n && cur + ttm[i] <= max_s){cur += ttm[i]; ++i;}
    cur = 0;
    for (int j = 0; j < i; ++j){
        cur = cur + ttm[j];
        if (cur > 350) ctm += (cur - 350);
    }
    printf("%d %d\n", i, ctm);
    return 0;
}