#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
typedef long long LL;
using namespace std;
const int N = 100005;

int n;
pair<int , int> a[N];
int pren[N] , prex[N] , sufn[N] , sufx[N];

inline LL square(int x) {
    return (LL)x * x;
}

bool check(LL D) {
    if (square(a[n].first - a[1].first) <= D)
        return 1;
    for (int T = 0 ; T < 2 ; ++ T) {
        for (int i = 1 ; i <= n ; ++ i) {
            pren[i] = min(pren[i - 1] , a[i].second);
            prex[i] = max(prex[i - 1] , a[i].second);
        }
        for (int i = n ; i > 0 ; -- i) {
            sufn[i] = min(sufn[i + 1] , a[i].second);
            sufx[i] = max(sufx[i + 1] , a[i].second);
        }
        int l1 , l2 , r1 , r2;
        r1 = n , r2 = 0;
        l1 = 1 , l2 = n + 1;
        for (int i = 1 ; i <= n && a[i].first <= 0 ; ++ i) {
            int l , r , m;

            l = i - 1 , r = n;
            while (l < r) {
                m = l + r + 1 >> 1;
                if (abs(a[m].first) <= -a[i].first && square(a[m].first - a[i].first) <= D)
                    l = m;
                else
                    r = m - 1;
            }
            int R = l;
            l = i , r = n + 1;
            while (l < r) {
                m = l + r >> 1;
                if (square(max(prex[i - 1] , sufx[m + 1]) - min(pren[i - 1] , sufn[m + 1])) <= D &&
                    square(a[i].first) + max(square(max(prex[i - 1] , sufx[m + 1])) , square(min(pren[i - 1] , sufn[m + 1]))) <= D)
                    r = m;
                else
                    l = m + 1;
            }
            int L = r;
            /*while (r1 > 0 && a[r1].first > -a[i].first)
                -- r1;
            while (r2 < n && square(a[r2 + 1].first - a[i].first) <= D)
                ++ r2;
            while (l1 <= n && square(max(prex[i - 1] , sufx[l1 + 1]) - min(pren[i - 1] , sufn[l1 + 1])) > D)
                ++ l1;
            while (l2 > 1 && square(a[i].first) + max(square(max(prex[i - 1] , sufx[l2])) , square(min(pren[i - 1] , sufn[l2]))) <= D)
            -- l2;
            int l = max(l1 , l2) , r = min(r1 , r2);
            if (max(i , l) <= r)
            return 1;*/
            if (L <= R)
                return 1;
        }
        reverse(a + 1 , a + n + 1);
        for (int i = 1 ; i <= n ; ++ i)
            a[i].first = -a[i].first;
    }
    return 0;
}

int main() {
    scanf("%d" , &n);
    int mx = -1 << 30 , mn = 1 << 30;
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d" , &a[i].first , &a[i].second);
        mx = max(mx , a[i].second);
        mn = min(mn , a[i].second);
    }
    sort(a + 1 , a + n + 1);
    a[0].first = -1 << 30;
    a[n + 1].first = 1 << 30;
    LL l = 0 , r = square(mx - mn) , m;
    check(0);
    while (l < r) {
        m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    printf("%lld\n" , r);
    return 0;
}