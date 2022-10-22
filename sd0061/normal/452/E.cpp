#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;

const int N = 300005;
int n , K; char s[N];
int sa[N] , t1[N] , t2[N] , c[N];
int rank[N] , height[N];
pair<int , int> f[19][N];
void buildsa(int m)
{
    int i , k , *x = t1 , *y = t2;
    for (i = 0 ; i < m ; ++ i) c[i] = 0;
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 ; k <= n ; k <<= 1) {
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
    for (i = 0 ; i < n ; ++ i) {
        if (k) -- k; if (!rank[i]) continue;
        int j = sa[rank[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[rank[i]] = k;
    }
    for (i = 0 ; i < n ; ++ i)
        f[0][i] = make_pair(height[i] , i);
    for (int j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 < n ; ++ i)
            f[j][i] = min(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
}
int L1 , L2 , L3;
int sf1[N] , sf2[N] , sf3[N];
LL ans[N]; const int Q = 1e9 + 7;
/*
    L1 [0 , L1)
    L2 [L1 + 1 , L1 + L2 + 1)
    L3 [L1 + L2 + 2 , L1 + L2 + L3 + 2)
*/

pair<int , int> RMQ(int x , int y) {
    int j = log2(y - x + 1);
    return min(f[j][x] , f[j][y - (1 << j) + 1]);
}

void cal(int l , int r) {
    if (l >= r) return;
    pair<int , int> j = RMQ(l + 1 , r);
    int m = j.second;
    // [l , m - 1] , [m , r];
    cal(l , m - 1);
    cal(m , r);
    ans[j.first] += (LL)(sf1[r] - sf1[m - 1]) * (sf2[m - 1] - sf2[l - 1]) * (sf3[m - 1] - sf3[l - 1]) % Q;
    ans[j.first] += (LL)(sf2[r] - sf2[m - 1]) * (sf1[m - 1] - sf1[l - 1]) * (sf3[m - 1] - sf3[l - 1]) % Q;
    ans[j.first] += (LL)(sf3[r] - sf3[m - 1]) * (sf2[m - 1] - sf2[l - 1]) * (sf1[m - 1] - sf1[l - 1]) % Q;
    ans[j.first] += (LL)(sf1[m - 1] - sf1[l - 1]) * (sf2[r] - sf2[m - 1]) * (sf3[r] - sf3[m - 1]) % Q;
    ans[j.first] += (LL)(sf2[m - 1] - sf2[l - 1]) * (sf1[r] - sf1[m - 1]) * (sf3[r] - sf3[m - 1]) % Q;
    ans[j.first] += (LL)(sf3[m - 1] - sf3[l - 1]) * (sf2[r] - sf2[m - 1]) * (sf1[r] - sf1[m - 1]) % Q;
    ans[j.first] %= Q;
}

void work() {
    int i , j , k;
    scanf("%s" , s);
    L1 = n = strlen(s);
    s[n ++] = '@';
    scanf("%s" , s + n);
    n += (L2 = strlen(s + n));
    s[n ++] = '$';
    scanf("%s" , s + n);
    n += (L3 = strlen(s + n));
    s[n ++] = '%';
    buildsa(128);
    for (i = 3 ; i < n ; ++ i) {
        //printf("%s\n" , s + sa[i]);
        sf1[i] = sf1[i - 1];
        sf2[i] = sf2[i - 1];
        sf3[i] = sf3[i - 1];
        if (sa[i] < L1)
            ++ sf1[i];
        else if (sa[i] < L1 + L2 + 1)
            ++ sf2[i];
        else
            ++ sf3[i];
    }
    cal(3 , n - 1);
    for (i = min(L1 , min(L2 , L3)) ; i >= 1 ; -- i) {
        ans[i - 1] += ans[i];
        ans[i - 1] %= Q;
    }
    for (i = 1 ; i <= min(L1 , min(L2 , L3)) ; ++ i)
        printf("%d " , (int)ans[i]);
    puts("");
}

int main()
{
    work();
    return 0;
}