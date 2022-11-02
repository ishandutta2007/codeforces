#include <bits/stdc++.h>
using namespace std;

char s[5][100] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
char t[1000];
int n;

int main() {
   // freopen("r.txt", "r", stdin);
    gets(t);
    n = strlen(t);
    int cnt = 0;
    for (int i = 0; i < n; i ++) for (int k = 0; k < 5; k ++) {
        int m = strlen(s[k]);//printf("%d\n", m);
        bool flag = 1;
        for (int j = 0; j < m; j ++) if (i + j >= n || t[i+j] != s[k][j]) flag = 0;
        if (flag) cnt ++;
    }//printf("%d\n", cnt);
    if (cnt == 1) puts("YES");
    else puts("NO");

    return 0;
}