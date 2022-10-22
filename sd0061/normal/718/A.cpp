#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char str[N];
int n , K;

int add(int x) {
    if (str[x] == '.')
        return add(x - 1);
    ++ str[x];
    while (x >= 0 && str[x] >= '0' + 10) {
        str[x] -= 10;
        if (x == 0 || str[x - 1] == '.') {
            if (x == 0) {
                return 1;
            } else {
                return add(x - 2);
            }
        } else {
            str[x - 1] ++;
            -- x;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d" , &n , &K);
    scanf("%s" , str);
    n = strlen(str);
    int p = -1;
    for (int i = 0 ; i < n ; ++ i) {
        if (str[i] == '.')  {
            p = i;
            break;
        }
    }
    if (p == -1 || K == 0) {
        puts(str);
    } else {
        int q = -1;
        for (int i = p + 1 ; i < n ; ++ i) {
            if (str[i] >= '5') {
                q = i;
                break;
            }
        }
        if (q == -1) {
            puts(str);
        } else {
            int ww = 0;
            while (K --) {
                while (q > p && str[q] < '5') {
                    -- q;
                }
                if (q == p) break;
                str[q] = 0;
                int w = add(q - 1);
                if (w) ww = 1;
                -- q;
            }
            str[p] = 0;
            if (ww) printf("1");
            printf("%s" , str);
            while (str[n - 1] == '0') {
                str[-- n] = 0;
            }

            if (str[p + 1] != 0) {
                printf(".%s" , str + p + 1);
            }
        }

    }
}