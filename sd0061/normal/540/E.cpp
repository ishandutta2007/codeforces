#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200005;
int n;
map<int , int> p;
int a[N] , b[N] , d[N] , D , c[N];
int main() {
    scanf("%d" , &n);
    while (n --) {
        int x , y;
        scanf("%d%d" , &x , &y);
        if (!p.count(x)) p[x] = x;
        if (!p.count(y)) p[y] = y;
        swap(p[x] , p[y]);
    }
    n = 0;
    for (auto &it : p) {
        b[n] = it.first;
        a[n ++] = it.second;
        d[D ++] = it.second;        
    }
    LL res = 0;
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (int i = 0 ; i < n ; ++ i) {       
        a[i] = lower_bound(d , d + D , a[i]) - d + 1;
        b[i] = lower_bound(d , d + D , b[i]) - d + 1;
        for (int j = a[i] + 1 ; j <= D ; j += j & -j)
            res += c[j];
        for (int j = a[i] ; j > 0 ; j -= j & -j)
            ++ c[j];
    }
    memset(c , 0 , sizeof(c));
    for (int i = 0 ; i < n ; ++ i) {
        int x = d[b[i] - 1] - 1; // [1 , x] [p_i > d[a[i] - 1]]
        res += max(0 , x - d[a[i] - 1]);
        for (int j = a[i] + 1 ; j <= D ; j += j & -j)
            res += c[j];
        for (int j = b[i] ; j > 0 ; j -= j & -j)
            -- c[j];
    }
    memset(c , 0 , sizeof(c));
    for (int i = n - 1 ; i >= 0 ; -- i) {
        int x = d[b[i] - 1] + 1; // [x , +oo] [p_i < d[a[i] - 1]]
        res += max(0 , d[a[i] - 1] - x);
        for (int j = a[i] - 1 ; j > 0 ; j -= j & -j)
            res += c[j];
        for (int j = b[i] ; j <= D ; j += j & -j)
            -- c[j];
    }
    cout << res << endl;
    return 0;
}