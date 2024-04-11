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

const int inf = (int)1e9;

int tt[200], res[200];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        tt[i] = inf;
    }
    for(int i = 0; i < m; i++){
        int l, r, t, c;
        scanf("%d %d %d %d", &l, &r, &t, &c);
        for(int j = l - 1; j < r; j++){
            if(t < tt[j]){
                tt[j] = t;
                res[j] = c;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += res[i];
    }
    printf("%d\n", ans);
    return 0;
}