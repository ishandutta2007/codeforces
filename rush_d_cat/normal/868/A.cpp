#include <iostream>
using namespace std;
char s[3], str[102][3];
int n;
int main() {
    scanf("%s", s+1);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%s", str[i] + 1);
    int ok = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (str[i][2] == s[1] && str[j][1] == s[2])
                ok = 1;
            if (str[i][1] == s[1] && str[i][2] == s[2])
                ok = 1;
        }
    }
    printf("%s\n", ok ? "YES" : "NO");
}