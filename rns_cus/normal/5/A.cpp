#include <bits/stdc++.h>
using namespace std;

char s[111];

int main() {
    int rlt = 0, cur = 0;
    while (gets(s)) {
        if (s[0] == '+') cur ++;
        else if (s[0] == '-') cur --;
        else {
            int cnt = 0;
            for (int i = 0; s[i]; i ++) {
                cnt ++;
                if (s[i] == ':') cnt = 0;
            }
            rlt += cnt * cur;
        }

    }
    printf("%d\n", rlt);

    return 0;
}