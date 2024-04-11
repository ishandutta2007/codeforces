#include <bits/stdc++.h>
using namespace std;

#define N 200100

char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int ans = 0, cnt = 0;
        for (int i = n; i >= 1; i --) {
            if (s[i] == 'B') cnt ++;
            else {
                if (cnt == 0) ans ++;
                else cnt --;
            }
        }
        if (cnt & 1) ans ++;
        printf("%d\n", ans);
    }

    return 0;
}