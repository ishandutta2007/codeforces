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
typedef unsigned long long ULL;
#define N 100005
int n ; char s[N];
int sa[N] , t1[N] , t2[N] , c[N];
int rank[N] , height[N];
int f[16][N] , LOG[N];
void buildsa(int m)
{
    int i , k , *x = t1 , *y = t2;
    for (i = 0 ; 1 << i <= n ; ++ i) LOG[1 << i] = i;
    for (i = 2 ; i <= n ; ++ i) if (!LOG[i]) LOG[i] = LOG[i - 1];
    for (i = 0 ; i < m ; ++ i) c[i] = 0;
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 ; k <= n ; k <<= 1)
    {
        int p = 0;
        for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
        for (i = 0 ; i < m ; ++ i) c[i] = 0;
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i)
            x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) ? p - 1 : p ++;
        if (p >= n) break;
        m = p;
    }
    k = 0;
    for (i = 0 ; i < n ; ++ i) rank[sa[i]] = i;
    for (i = 0 ; i < n ; ++ i)
    {
        if (k) -- k; if (!rank[i]) continue;
        int j = sa[rank[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[rank[i]] = k;
    }
    memset(f , 0 , sizeof(f));
    for (i = 0 ; i < n ; ++ i)
        f[0][i] = height[i];
    for (int j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 < n ; ++ i)
            f[j][i] = min(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
}

int LCP(int x , int y)
{
    if (x == y) return n - x;
    x = rank[x] , y = rank[y];
    if (x > y) swap(x , y); ++ x;
    int j = LOG[y - x + 1];
    return min(f[j][x] , f[j][y - (1 << j) + 1]);
}
vector< pair<int , int> > res;
void work() {
    int i , j , k , x , y;
    scanf("%s" , s);
    n = strlen(s) + 1;
    buildsa(127);
    -- n;
    //for (i = 1 ; i <= n ; ++ i)
    //    puts(s + sa[i]);
    for (i = n - 1 ; i >= 0 ; -- i) {
        if (LCP(0 , i) == n - i) {
            int l = rank[0] , r = n , m;
            while (l < r) {
                m = l + r + 1>> 1;
                if (LCP(i , sa[m]) >= n - i)
                    l = m;
                else
                    r = m - 1;
            }
            res.push_back(make_pair(n - i , l - rank[i] + 1));
        }
    }
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i) {
        printf("%d %d\n" , res[i].first , res[i].second);
    }

}

int main() {
    work();
    return 0;
}