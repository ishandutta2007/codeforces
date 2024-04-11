#include <iostream>
#include <cstring>
using namespace std;
const int N = 1002;
int t;
char s[N];
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%s", s+1);
        int n = strlen(s + 1);
        int vis[30] = {0};
        for (int i = 1, j = 1; i <= n; i = j) {
            while (j <= n && s[i] == s[j]) j ++;
            if ((j - i) % 2 == 1) vis[s[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; i ++) if (vis[i]) printf("%c", i + 'a');
        printf("\n");
    }
}