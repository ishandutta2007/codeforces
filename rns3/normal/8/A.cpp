#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100011

char s[N], ss[N], t[N], u[N];

bool ok(char *s, char *t, char *u){
    int ss = strlen(s), tt = strlen(t), uu = strlen(u);
    int x = strstr(s, t) - s;
    if(x < 0) return 0;
    int y = strstr(s + x + tt, u) - s;
    if(y < 0) return 0;
    return 1;
}

int main(){
    scanf("%s %s %s",  s, t, u);
    int len = strlen(s);
    strcpy(ss, s);
    reverse(ss, ss + len);

    bool f = ok(s, t, u);
    bool b = ok(ss, t, u);

    if(f && b) puts("both");
    else if(f) puts("forward");
    else if(b) puts("backward");
    else puts("fantasy");
}