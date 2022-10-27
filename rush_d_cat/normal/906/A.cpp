#include <iostream>
#include <cstring>
using namespace std;
int n;
char op[3], str[100000+10];
int st[1002], ans;
bool finish = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", op+1);
        scanf("%s", str+1);
        int len = strlen(str+1);
        if (finish) {
            if (op[1] == '!' || op[1] == '?')  ans ++;
            continue;
        }

        if (op[1] == '!') {
            bool vis[27];
            memset(vis,0,sizeof(vis));
            for (int p=1;p<=len;p++)
                vis[str[p]-'a'] = 1;   
            for (int p=0;p<26;p++) {
                if (vis[p] == 0) st[p+'a'] = 1;
            }
        }

        if (op[1] == '?') {
            for (int p=1;p<=len;p++)
                st[str[p]] = 1;            
        }

        if (op[1] == '.') {
            for (int p=1;p<=len;p++)
                st[str[p]] = 1;
        }

        int cnt = 0;
        for (int p='a';p<='z';p++) if (st[p]) cnt ++;
        //printf("cnt = %d\n", cnt);
        if (cnt == 25)
            finish = 1;
    }

    printf("%d\n", ((ans-1) < 0) ? 0 : ans-1);
}