#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

char str[305];

int query(int len)
{
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == -1 || ans == 0) exit(0);
    return ans;
}

int main()
{
    for (int i = 0; i < 300; i++) str[i] = 'a';
    int acnt = 300 - query(300);
    for (int i = 0; i < 300; i++) str[i] = 'b';
    int bcnt = 300 - query(300);
    int n = acnt + bcnt;
    if (acnt == 0) {
        for (int i = 0; i < bcnt; i++) str[i] = 'b';
        query(bcnt);
    }
    if (bcnt == 0) {
        for (int i = 0; i < acnt; i++) str[i] = 'a';
        query(acnt);
    }
    for (int i = 0; i < n; i++) str[i] = 'a';
    int cnt = bcnt;
    for (int i = 0; i < n; i++) {
        str[i] = 'b';
        int res = query(n);
        if (res >= cnt)
            str[i] = 'a';
        else
            cnt = res;
    }
    return 0;
}