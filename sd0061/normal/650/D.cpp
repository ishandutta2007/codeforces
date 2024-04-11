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
const int N = 1000005;

int n , m , a[N] , d[N] , D;
pair<int , int> q[N];
int c[N] , L[N] , R[N] , cnt[N];
int might[N] , must[N];
int res[N] , K , l[N] , r[N];
pair<int , int> b[N];

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        d[D ++] = a[i];
    }
    for (int i = 1 ; i <= m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        q[i] = make_pair(x , y);
        d[D ++] = y;
    }
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = lower_bound(d , d + D , a[i]) - d + 1;
    }
    for (int i = 1 ; i <= m ; ++ i) {
        q[i].second = lower_bound(d , d + D , q[i].second) - d + 1;
    }

    memset(c , 0 , sizeof(c));
    for (int i = 1 ; i <= n ; ++ i) {
        int &v = L[i];
        for (int j = a[i] - 1 ; j > 0 ; j -= j & -j)
            v = max(v , c[j]);
        ++ v;
        for (int j = a[i] ; j <= D ; j += j & -j)
            c[j] = max(c[j] , v);
    }
    
    memset(c , 0 , sizeof(c));
    for (int i = n ; i > 0 ; -- i) {
        int &v = R[i];
        for (int j = a[i] + 1 ; j <= D ; j += j & -j)
            v = max(v , c[j]);
        ++ v;
        for (int j = a[i] ; j > 0 ; j -= j & -j)
            c[j] = max(c[j] , v);
    }

    int len = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        len = max(len , L[i] + R[i]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (L[i] + R[i] == len) {
            might[i] = 1;
            ++ cnt[L[i]];
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (L[i] + R[i] == len && cnt[L[i]] == 1) {
            might[i] = 0;
            must[i] = 1;
        }
        //printf("%d %d\n" , might[i] , must[i]);
    }
    
    K = 0;
    for (int i = 1 ; i <= m ; ++ i) {
        int x = q[i].first;
        if (must[x]) {            
            res[i] = len - 2;
        } else {
            res[i] = len - 1;
        }        
        b[K ++] = make_pair(x , i);
    }
    sort(b , b + K);
    
    memset(c , 0 , sizeof(c));
    for (int i = 0 , j = 1 ; i < K ; ++ i) {
        //cout << b[i].first << ' ' << b[i].second << endl;
        int x = b[i].first;
        while (j <= n && j < x) {
            int v = L[j];
            for (int k = a[j] ; k <= D ; k += k & -k)
                c[k] = max(c[k] , v);
            ++ j;
        }
        int p = b[i].second;
        int y = q[p].second , v = 0;
        for (int k = y - 1 ; k > 0 ; k -= k & -k)
            v = max(v , c[k]);
        l[p] = ++ v;
    }

    memset(c , 0 , sizeof(c));
    for (int i = K - 1 , j = n ; i >= 0 ; -- i) {
        int x = b[i].first;
        while (j > 0 && j > x) {
            int v = R[j];
            for (int k = a[j] ; k > 0 ; k -= k & -k)
                c[k] = max(c[k] , v);
            -- j;
        }
        int p = b[i].second;
        int y = q[p].second , v = 0;
        for (int k = y + 1 ; k <= D ; k += k & -k)
            v = max(v , c[k]);
        r[p] = ++ v;
    }

    for (int i = 0 ; i < K ; ++ i) {
        int p = b[i].second;
        res[p] = max(res[p] , l[p] + r[p] - 1);
    }
    for (int i = 1 ; i <= m ; ++ i) {
        printf("%d\n" , res[i]);
    }
    return 0;
}