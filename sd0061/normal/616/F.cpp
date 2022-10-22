#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 600005;

int sa[N] , t1[N] , t2[N] , c[N];
int Rank[N] , height[N];
void buildsa(int *s , int n , int m) {
    int i , k , p , a1 , a2 , *x = t1 , *y = t2;
    memset(c , 0 , m << 2);
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 , p = 0; k < n ; k <<= 1 , p = 0) {
        for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
        memset(c , 0 , m << 2);
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i) {
            a1 = sa[i - 1] + k < n ? y[sa[i - 1] + k] : -1;
            a2 = sa[i] + k < n ? y[sa[i] + k] : -1;
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && a1 == a2) ? p - 1 : p ++;
        }
        if (p >= n) break; m = p;
    }
    for (i = 0 ; i < n ; ++ i) Rank[sa[i]] = i;
    for (i = 0 , k = 0; i < n ; ++ i) {
        if (k) -- k; if (!Rank[i]) continue;
        int j = sa[Rank[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[Rank[i]] = k;
    }
}

int n , str[N] , v[N] , pos[N] , len[N];
char S[N];
int L[N] , R[N] , stack[N] , top;
LL sum[N];

void work() {
    int Len = 0;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , S);
        int l = strlen(S);
        for (int j = 0 ; S[j] ; ++ j) {
            len[Len] = l - j;
            str[Len ++] = (int)S[j] + n;
        }
        pos[i] = Len;
        str[Len ++] = i + 1;
    }
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &v[i]);
    buildsa(str , Len , n + 150);

    LL res = 0;
    for (int i = n ; i < Len ; ++ i) {
        int j = lower_bound(pos , pos + n , sa[i]) - pos;
        sum[i + 1] = sum[i] + v[j];
        if (height[i] < len[sa[i]] && height[i + 1] < len[sa[i]]) {
            res = max(res , (LL)v[j] * len[sa[i]]);
        }
        //printf("%d : %d\n" , sa[i] , j);
    }
    for (int i = 1 ; i < Len ; ++ i) {
        while (top && height[i] < height[stack[top - 1]]) {
            R[stack[-- top]] = i;
        }
        stack[top ++] = i;
    }
    while (top)
        R[stack[-- top]] = Len;
    for (int i = Len - 1 ; i >= 1 ; -- i) {
        while (top && height[i] < height[stack[top - 1]]) {
            L[stack[-- top]] = i;
        }
        stack[top ++] = i;
    }
    while (top)
        L[stack[-- top]] = 0;
    for (int i = 1 ; i < Len ; ++ i) {
        if (!height[i]) continue;
        int l = L[i] , r = R[i];
        res = max(res , (sum[r] - sum[l]) * height[i]);
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}