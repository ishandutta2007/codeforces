#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 1024;
typedef long long LL;

int n , Q;
int top , bot;
struct block {
    int len , dig;
    LL s[M] , delta;
    LL a[M];
    int L[M] , R[M];
    void rebuild() {
        dig = 0;
        for (int i = 0 ; i < len ; ++ i) {
            s[i] += delta;
            a[dig ++] = s[i];
        }
        sort(a , a + dig);
        dig = unique(a , a + dig) - a;
        memset(L , 0x3f , sizeof(L));
        memset(R , 0xc0 , sizeof(R));
        for (int i = 0 ; i < len ; ++ i) {
            int j = lower_bound(a , a + dig , s[i]) - a;
            L[j] = min(L[j] , i);
            R[j] = max(R[j] , i);
        }
        delta = 0;
    }
    void query(int offset , LL x) {
        x -= delta;
        int j = lower_bound(a , a + dig , x) - a;
        if (j < dig && a[j] == x) {
            top = min(top , offset + L[j]);
            bot = max(bot , offset + R[j]);
        }
    }
}b[M];



void work() {
    int i , j , k , l , r , x;
    scanf("%d%d" , &n , &Q);
    int B = (n + M - 1) / M;
    for (i = 0 ; i < B ; ++ i) {
        int L = i << 10 , R = min(n , L + M);
        b[i].len = R - L;
        b[i].delta = 0;
        for (j = L ; j < R ; ++ j) {
            scanf("%I64d" , &b[i].s[j - L]);
        }
        b[i].rebuild();
    }
    while (Q --) {
        scanf("%d" , &i);
        if (i == 1) {
            scanf("%d%d%d" , &l ,&r , &x);
            -- l;
            j = l >> 10 , k = r >> 10;
            if (j == k) {
                int L = j << 10;
                for (i = l ; i < r ; ++ i) {
                    b[j].s[i - L] += x;
                }
                b[j].rebuild();
            } else {
                for (i = j + 1 ; i < k ; ++ i)
                    b[i].delta += x;
                int L = j << 10;
                int R = min((j + 1) * M , n);
                for (i = l ; i < R ; ++ i) {
                    b[j].s[i - L] += x;
                }
                b[j].rebuild();
                L = k << 10;
                for (i = L ; i < r ; ++ i) {
                    b[k].s[i - L] += x;
                }
                b[k].rebuild();
            }

        } else {
            scanf("%d" , &x);
            top = 1 << 30 , bot = -1 << 30;
            for (i = 0 ; i < B ; ++ i)
                b[i].query(i << 10 , x);
            if (top > n)
                puts("-1");
            else
                printf("%d\n" , bot - top);
        }

    }
}

int main() {
    work();
    return 0;
}