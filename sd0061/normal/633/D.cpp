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
typedef long long LL;
using namespace std;
const int N = 1005;

int n , a[N] , d[N] , D;
int cnt[N] , nxt[N][N];
int res;

void dfs(int i , int j , int s) {
    res = max(res , s);
    int k = nxt[i][j];    
    if (k == -1) {
        return;
    } else if (cnt[k]) {
        -- cnt[k];
        dfs(j , k , s + 1);
        ++ cnt[k];
    }
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        d[D ++] = x;
        a[i] = x;
    }
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (int i = 0 ; i < n ; ++ i) {
        a[i] = lower_bound(d , d + D , a[i]) - d;
        ++ cnt[a[i]];
    }
    for (int i = 0 ; i < D ; ++ i)
        for (int j = 0 ; j < D ; ++ j) {            
            int k = lower_bound(d , d + D , d[i] + d[j]) - d;
            if (k >= D || d[k] != d[i] + d[j])
                nxt[i][j] = -1;
            else
                nxt[i][j] = k;
        }
    res = 2;
    for (int i = 0 ; i < D ; ++ i) {
        -- cnt[i];
        for (int j = 0 ; j < D ; ++ j) {
            if (!cnt[j])
                continue;
            -- cnt[j];
            dfs(i , j , 2);
            ++ cnt[j];
        }
        ++ cnt[i];
    }
    cout << res << endl;
    return 0;
}