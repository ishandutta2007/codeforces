#include<bits/stdc++.h>
using namespace std;
int f[400], g[400];
#define N 1111111
int sto[N];
bool pp[N];
char a[N], b[N];
int main(){
    //freopen("J.in","r",stdin);
    scanf("%s%s", a, b);
    int la = strlen(a);
    int lb = strlen(b);
    for(int i = 0; i < la; i ++) {
        f[a[i]] ++;
    }
    for(int i = 0; i < lb; i ++) {
        g[b[i]] ++;
    }
    int T = 0, po = -1;
    for(int i = 'a'; i <= 'z'; i ++) {
        if(f[i] != g[i]) T ++, po = i;
    }
    if(T != 1) {puts("0");return 0;}
    int CNT = 0;
    pp[la] = 1;
    for(int i = la - 1; i >= 1; i --) {
        if(pp[i + 1] == 0) {pp[i] = 0;continue;}
        if(a[i] != b[i-1]) {pp[i] = 0;continue;}
        pp[i] = 1;
    }
    int ok = 1;
    for(int i = 0; i < la; i ++) {
        if(a[i] == po) {
            if(ok && pp[i + 1])sto[CNT++] = i + 1;
        }
        if(a[i] != b[i]) ok = 0;
    }
    printf("%d\n", CNT);
    for(int i = 0; i < CNT ;i ++) printf("%d ", sto[i]);
    puts("");
    return 0;
}