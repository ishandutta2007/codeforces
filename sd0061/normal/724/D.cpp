#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n , K;
char str[N] , res[N];
int W[N] , L[N] , R[N];

int work(int l , int r , char c) {
    int m = 0 , w = l - 1;
    for (int i = l ; i < min(n , r + K); ++ i) {
        if (str[i] == c) {
            L[m] = max(l , i - K + 1);
            R[m ++]  = i;
        }
    }
    int i = 0 , cnt = 0;
    while (w < min(r , n - K + 1)) {
        int y = w;
        while (i < m && L[i] <= w + 1) {
            y = max(y , R[i ++]);
        }
        if (y == w) {
            return -1;
        }
        w = y;
        ++ cnt;
    }
    return cnt;
}

int main() {
    scanf("%d%s" , &K , str);
    n = strlen(str);
    strcpy(res , str);
    sort(res , res + n);

    for (int k = 0 ; k < 26 ; ++ k) {
        memset(W , 0 , sizeof(W));
        static char t[N];
        int len = 0;
        for (int i = 0 ; i < n ; ++ i) {
            if (str[i] < 'a' + k) {
                ++ W[max(0 , i - K + 1)];
                -- W[i + 1];
                t[len ++] = str[i];
            }
        }
        for (int i = 1 ; i <= n ; ++ i) {
            W[i] += W[i - 1];
        }
        int cnt = 0;
        bool flag = 1;
        for (int i = 0 ; i < n ; ++ i) {
            if (!W[i] && i < n - K + 1) {
                int j = i;
                while (j < n - K + 1 && !W[j]) {
                    ++ j;
                }
                //printf("%d %d %d\n" , k , i , j - 1);
                int w = work(i , j - 1 , 'a' + k);
                if (w == -1) {
                    flag = 0;
                    break;
                }
                cnt += w;
                i = j - 1;
            }
        }
        if (flag) {
            while (cnt --) {
                t[len ++] = 'a' + k;
            }
            sort(t , t + len);
            t[len] = 0;
            if (strcmp(t , res) < 0) {
                strcpy(res , t);
            }
        }
    }
    puts(res);
}