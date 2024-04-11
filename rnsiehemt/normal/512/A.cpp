#include <bits/stdc++.h>

void no() {
    printf("Impossible\n");
    exit(0);
}

int N;
char a[105][105];
bool e[105][105];
int seen[105];
char ans[30]; int L;

void dfs(int a) {
    if (!seen[a]) {
        seen[a] = 1;
        for (int i = 0; i < 26; i++)
            if (e[a][i]) dfs(i);
        ans[L++] = 'a'+a;
        seen[a] = 2;
    }
    else if (seen[a] == 1) no();
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf(" %s", a[i]);
    
    for (int i = 0; i+1 < N; i++) {
        int L = strlen(a[i]), M = strlen(a[i+1]);
        bool eq = true;
        for (int j = 0; j < std::min(L, M); j++) {
            if (a[i][j] != a[i+1][j]) {
                eq = false;
                e[a[i][j]-'a'][a[i+1][j]-'a'] = true;
                break;
            }
        }
        if (eq && L > M) no();
    }

    for (int i = 0; i < 26; i++)
        if (!seen[i]) dfs(i);
    
    std::reverse(ans, ans+L);
    for (int i = 0; i < L; i++) printf("%c", ans[i]);
    printf("\n");
}