#include <bits/stdc++.h>
using namespace std;

#define N 1010

char s[10];
int sz[10];

char type[10][10] = {"S", "M", "L", "XL", "XXL"};

int main() {
//    freopen("1.in", "r", stdin);
    for (int i = 0; i < 5; i ++) scanf("%d", &sz[i]);
    int n;
    scanf("%d", &n);
    while (n --) {
        scanf("%s", s);
        int t = 0;
        if (s[0] == 'S') t = 0;
        else if (s[0] == 'M') t = 1;
        else if (s[0] == 'L') t = 2;
        else if (s[1] == 'L') t = 3;
        else t = 4;
        for (int k = 0; ; k ++) {
            int p = t + k;
            if (0 <= p && p < 5 && sz[p]) {
                sz[p] --;
                printf("%s\n", type[p]);
                break;
            }
            p = t - k;
            if (0 <= p && p < 5 && sz[p]) {
                sz[p] --;
                printf("%s\n", type[p]);
                break;
            }
        }
    }
}