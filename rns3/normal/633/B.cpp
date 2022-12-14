#include <bits/stdc++.h>
using namespace std;
#define M 10010010

int cnt;
int a[M];

int main() {
    //freopen("B1.in", "r", stdin);
    int m;
    scanf("%d", &m);
    int five = 0;
    for (int i = 1; ; i++) {
        int x = i;
        while (x % 5 == 0) {
            x /= 5;
            five ++;
        }
        //printf("five = %d, i = %d\n", five, i);
        if (five > m) {
            break;
        }
        if (five == m) {
            a[cnt++] = i;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}