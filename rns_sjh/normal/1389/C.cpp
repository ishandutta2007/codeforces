#include<bits/stdc++.h>
using namespace std;

char s[200010];

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        memset(s, 0, sizeof s);
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for(int k = 0; k < 10; k ++) {
            for(int m = 0; m < 10; m ++) {
                int l = 0;
                for(int i = 0; i < n; i ++) {
                    if(l % 2 == 0 && s[i] == '0' + k) {
                        l ++;
                    }
                    if(l % 2 == 1 && s[i] == '0' + m) {
                        l ++;
                    }
                }
                if(k != m) l = l / 2 * 2;
                if(k == m) l /= 2;
                ans = max(l, ans);
            }
        }
        printf("%d\n", n - ans);
    }
}