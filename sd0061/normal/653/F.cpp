#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 500005;

int n;
char str[N];

int sa[N] , t1[N] , t2[N] , c[N];
int Rank[N] , height[N];
void buildsa(char *s , int n , int m) {
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

int s[N] , f[19][N] , LOG[N];
vector<int> V[N + N];

inline int RMQ(int l , int r) {
    int j = LOG[r - l + 1];
    return min(f[j][l] , f[j][r - (1 << j) + 1]);
}

int main() {
    scanf("%d%s" , &n , str);
    for (int i = 0 ; i < n ; ++ i) {
        s[i + 1] = s[i] + (str[i] == '(' ? 1 : -1);
    }
    for (int i = 0 ; i <= n ; ++ i) {
        V[s[i] + n].push_back(i);
        f[0][i] = s[i];
    }
    for (int i = 2 ; i <= n + 2 ; ++ i)
        LOG[i] = LOG[i >> 1] + 1;
    for (int j = 1 ; 1 << j <= n + 1 ; ++ j)
        for (int i = 0 ; i + (1 << j) - 1 <= n ; ++ i) {
            f[j][i] = min(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
        }
    buildsa(str , n , 127);

    LL res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int l = sa[i] , r1 = sa[i] + height[i];

        int top = r1 - 1 , bot = n - 1;
        while (top < bot) {
            int mid = top + bot + 1 >> 1;
            if (RMQ(l + 1 , mid + 1) >= s[l])
                top = mid;
            else
                bot = mid - 1;
        }
        int r2 = top;
        if (r1 <= r2) {
            ++ r1 , ++ r2;
            int v = s[l] + n;
            res += upper_bound(V[v].begin() , V[v].end() , r2) - lower_bound(V[v].begin() , V[v].end() , r1);
        }
    }
    cout << res << endl;
    return 0;
}