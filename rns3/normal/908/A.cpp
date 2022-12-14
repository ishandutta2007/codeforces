#include <bits/stdc++.h>
using namespace std;

char s[60];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i ++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ans ++;
        else if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') ans ++;
    }
    printf("%d\n", ans);
    return 0;
}