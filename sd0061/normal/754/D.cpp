#include <bits/stdc++.h>
using namespace std;
const int N = 600005;

int n , K;
int L[N] , R[N] , d[N] , D;
struct range {
    int l , r , id;
    bool operator < (const range &R) const {
        return make_pair(l , r) < make_pair(R.l , R.r);
    }
} a[N];
int c[N];
int main() {
    scanf("%d%d" , &n , &K);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , L + i , R + i);
        -- L[i];
        d[++ D] = L[i];
        d[++ D] = R[i];
    }
    sort(d + 1 , d + D + 1);
    D = unique(d + 1 , 1 + d + D) - d - 1;
    for (int i = 0 ; i < n ; ++ i) {
        L[i] = lower_bound(d + 1 , d + D + 1 , L[i]) - d;
        R[i] = lower_bound(d + 1 , d + D + 1 , R[i]) - d;
        a[i] = {L[i] , R[i] , i + 1};
    }
    sort(a , a + n);
    int res = -1 , ll = -1 , rr = -1;
    for (int i = 1 , j = 0 ; i <= D ; ++ i) {
        while (j < n && a[j].l <= i) {
            for (int k = a[j].r ; k > 0 ; k -= k & -k) {
                ++ c[k];
            }
            ++ j;
        }
        int l = i , r = D;
        while (l < r) {
            int m = l + r + 1 >> 1 , sum = 0;
            for (int k = m ; k <= D ; k += k & -k) {
                sum += c[k];
            }
            if (sum >= K) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (d[l] - d[i] > res) {
            ll = i , rr = l;
            res = max(res , d[l] - d[i]);
        }
    }
    if (res == 0) {
        puts("0");
        for (int i = 1 ; i <= K ; ++ i) {
            printf("%d%c" , i , " \n"[i == K]);
        }
    } else {
        printf("%d\n" , res);
        for (int i = 0 ; i < n && K > 0 ; ++ i) {
            if (a[i].l <= ll && rr <= a[i].r) {
                -- K;
                printf("%d%c" , a[i].id , " \n"[!K]);
            }
        }

    }
}
/*
2 2
1 100
40 70
 */