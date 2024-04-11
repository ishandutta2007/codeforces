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
const int N = 200005;

int d , C , n , buy[N] , a[N];
pair<int , int> shop[N];
pair<int , int> Q[N];

int main() {
    scanf("%d%d%d" , &d , &C , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d" , &shop[i].first , &shop[i].second);
    }
    shop[++ n] = make_pair(0 , 0);
    shop[++ n] = make_pair(d , 0);    
    sort(shop + 1 , shop + n + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = shop[i].first;
        buy[i] = shop[i].second;
    }      
    int top = 0 , bot = -1 , m = 0;
    LL res = 0;
    buy[n] = -1 << 30;
    for (int i = 0 ; i <= n ; ++ i) {
        while (top <= bot && buy[Q[bot].first] >= buy[i]) {
            m -= Q[bot].second;
            res -= (LL)Q[bot].second * buy[Q[bot].first];
            -- bot;
        }
        if (i == n) break;
        if (m < C) {
            res += (LL)(C - m) * buy[i];
            Q[++ bot] = make_pair(i , C - m);
            m = C;
        }
        int x = a[i + 1] - a[i];
        while (top <= bot && x) {
            int delta = min(x , Q[top].second);
            Q[top].second -= delta;
            m -= delta;
            x -= delta;
            if (!Q[top].second)
                ++ top;
        }
        if (x) {
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n" , res);
    return 0;
}