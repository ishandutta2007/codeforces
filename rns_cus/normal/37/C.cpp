#include<bits/stdc++.h>
using namespace std;
#define N 1111
int n;
int a[N];
char s[N][N];
char t[N][N];
int id[N];
bool cmp(int i, int j) {
    return a[i] < a[j];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &a[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    sort(a + 1, a + n + 1);
    s[0][0] = 0;
    bool fg = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < a[i-1]; j ++) s[i][j] = s[i-1][j];
        int en = a[i-1];
        if(en){
            en --;
            s[i][en] ++;
            while(1) {
                if(s[i][en] > '1') {
                    if(!en) {fg = 0;break;}
                    s[i][en] = '0', s[i][en - 1] ++;
                    en --;
                }
                else break;

            }
        }
        if(!fg) break;
        for(int j = a[i-1]; j < a[i]; j ++) {
            s[i][j] = '0';
        }
        s[i][a[i]] = 0;
    }
    if(!fg) puts("NO");
    else {
        puts("YES");
        for(int i = 1; i <= n; i ++) strcpy(t[id[i]], s[i]);
        for(int i = 1; i <= n; i ++) puts(t[i]);
    }
    return 0;
}