#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int sx = 0, sy = 0, sz = 0;
    for(int i = 0; i < n; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        sx += x;
        sy += y;
        sz += z;
    }
    if(sx == 0 && sy == 0 && sz == 0){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}