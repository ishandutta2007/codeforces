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
const int N = 200005;
const int Q = 1e9 + 7;

int n , a[3] , t[N] , b[N];

bool check(int v) {
    int cnt = 0;
    int T = v;
    memcpy(b , t , sizeof(t));
    reverse(b , b + n);
    for (int i = 0 ; i < n && T ; ++ i)
        if (~b[i] && b[i] <= a[2]) {
            b[i] = -1;
            -- T;
            ++ cnt;
        }
    T = v;
    for (int i = 0 ; i < n && T ; ++ i)
        if (~b[i] && b[i] > a[1] && b[i] <= a[0] + a[1]) {
            b[i] = -1;
            -- T;
            ++ cnt;
        }
    int TT = T;
    for (int i = 0 ; i < n && TT ; ++ i)
        if (~b[i] && b[i] <= a[0]) {
            b[i] = -1;
            -- TT;
            ++ cnt;
        }
    TT = T;
    for (int i = 0 ; i < n && TT ; ++ i)
        if (~b[i] && b[i] <= a[1]) {
            b[i] = -1;
            -- TT;
            ++ cnt;
        }
    return cnt == n;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < 3 ; ++ i)
        scanf("%d" , &a[i]);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &t[i]);
    sort(a , a + 3);
    sort(t , t + n);
    if (t[n - 1] > a[0] + a[1] + a[2]) {
        puts("-1");
        return 0;
    }
    int cnt = 0;
    while (n > 0 && t[n - 1] > a[1] + a[2]) {//ABC
        ++ cnt;
        -- n;
    }
    int AA = 0;
    while (n > 0 && t[n - 1] > a[0] + a[2]) {//BC
        ++ cnt;
        -- n;
        ++ AA;
    } // max now <= AC
    for (int i = n - 1 ; i >= 0 && AA ; -- i) {
        if (t[i] <= a[0]) {
            t[i] = -1;
            -- AA;
        }
    }
    int m = 0;
    for (int i = 0 ; i < n ; ++ i)
        if (~t[i])
            t[m ++] = t[i];
    n = m;

    int BB = 0;
    while (n > 0 && t[n - 1] > max(a[0] + a[1] , a[2])) {//AC
        ++ cnt;
        -- n;
        ++ BB;
    } // max now <= AB
    for (int i = n - 1 ; i >= 0 && BB ; -- i) {
        if (t[i] <= a[1]) {
            t[i] = -1;
            -- BB;
        }
    }
    m = 0;
    for (int i = 0 ; i < n ; ++ i)
        if (~t[i])
            t[m ++] = t[i];
    n = m;
    
    
        int l = 0 , r = n;
        while (l < r) {
            int mm = l + r >> 1;
            if (check(mm))
                r = mm;
            else
                l = mm + 1;
        }
        cnt += r;
    
    cout << cnt << endl;
        

    
    return 0;
}