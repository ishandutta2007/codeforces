//11_e
#include <bits/stdc++.h>
using namespace std;

#define N 2000011
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

char s[N];
bool same[N];
int tot[N];
int a[N];

void repair(char *s){
    int len = strlen(s);
    int cnt = 0;
    for(int i = 0; i < len - 1; i ++) if(s[i] != 'X' && s[i] == s[i + 1]) {
        same[i] = 1;
    }
    tot[0] = 0;
    for(int i = 1; i < len; i ++){
        tot[i] = tot[i - 1];
        if(same[i - 1]) tot[i] ++;
    }
    for(int i = len - 1; i > 0; i --){
        s[i + tot[i]] = s[i];
        if(same[i - 1]) s[i + tot[i] - 1] = 'X';
    }
    len += tot[len - 1];
    s[len] = NULL;
}

double calc(char *s){
    int len = strlen(s);
    int cnt = 0, q = 0, sz = 0, pre = 0;
    for(int i = 0; i < len; i ++){
        char t = (q & 1) ? 'R' : 'L';
        if(s[i] == 'X') q ++;
        else if(s[i] == t) q ++, cnt ++, pre = 0;
        else q += 2, cnt ++, sz += pre, pre = !pre;
    }

    if(q & 1) q ++, sz += pre;
    if(cnt * 2 > q) cnt -= sz, q -= 2 * sz;
    return 100.0 * cnt / q;
}

int main(){
    ///freopen("e.in", "r", stdin);
    scanf("%s", s);
    repair(s);

    double ans = 0.0;
    int len = strlen(s);
    if(s[0] != 'X' && s[len - 1] == s[0]){
        s[len ++] = 'X';
        s[len] = NULL;
        ans = calc(s);

        for(int i = len - 1; i; i --) s[i] = s[i - 1];
        s[0] = 'X';
        ans = max(ans, calc(s));
    }
    else ans = calc(s);

    ans = 1e-6 * (int)(ans * 1e6 + 1e-6);
    printf("%.6lf\n", ans);
    ///return 9;
}