#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;

int n;
char str[N][N];
int deg[N];
bool g[N][N];

void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , str[i]);       

    for (i = 1 ; i < n ; ++ i) {
        for (j = 0 ; str[i - 1][j] && str[i][j] ; ++ j)
            if (str[i - 1][j] != str[i][j])
                break;
        if (str[i - 1][j] && str[i][j]) {
            if (!g[str[i - 1][j] - 'a'][str[i][j] - 'a']) {
                g[str[i - 1][j] - 'a'][str[i][j] - 'a'] = 1;
                ++ deg[str[i][j] - 'a'];
            }
        } else if (str[i - 1][j]) {
            puts("Impossible");
            return;
        }
            
    }
    stack<int> S;
    for (i = 0 ; i < 26 ; ++ i)
        if (!deg[i])
            S.push(i);
    char res[30] = {}; int cnt = 0;
    while (!S.empty()) {
        i = S.top() , S.pop();
        res[cnt ++] = i + 'a';
        for (j = 0 ; j < 26 ; ++ j)
            if (g[i][j]) {
                if (!-- deg[j])
                    S.push(j);
            }
    }
    if (cnt == 26)
        puts(res);
    else
        puts("Impossible");    
}

int main() {
    work();
    return 0;
}