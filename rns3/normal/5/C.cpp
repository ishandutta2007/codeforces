#include <stdio.h>
#include <string.h>

#define N 1000011

char s[N];
int sto[N], nsto;

int main(){
    //freopen("c.in", "r", stdin);
    gets(s);
    int len = strlen(s);
    nsto = 0;
    for(int i=0; i<len; i++){
        if(s[i] == '(') {sto[nsto ++] = i; continue;}
        if(!nsto) continue;
        int x = sto[nsto-1];
        s[i] = s[x] = ' ';
        nsto --;
    }
    int mx = 0, mxnum = 1;
    for(int i=0; i<len; i++) {
        if(s[i] != ' ') continue;
        int j;
        for(j=i; j<len; j++) if(s[j] != ' ') break;
        if(mx == j-i) mxnum ++;
        if(mx < j-i) mx = j-i, mxnum = 1;
        i = j;
    }
    printf("%d %d\n", mx, mxnum);
}