#include<bits/stdc++.h>
using namespace std;

#define N 1010

char s[N][N], t[N];
bool b = 0;
int n = 0, mxl = 0;

void print() {for(int i = 0; i < mxl + 2; i ++) putchar('*'); puts("");}
void print(char *p) {
    int l = strlen(p), i, spc;
    putchar('*');
    spc = mxl - l + b >> 1;
    if((mxl - l) & 1) b ^= 1;
    for(i = 1; i <= spc; i ++) putchar(' ');
    printf("%s", p);
    for(i += l; i <= mxl; i ++) putchar(' ');
    putchar('*');
    puts("");
}

int main() {
    int i, l;
    while(gets(t) > 0) {
        strcpy(s[++ n], t);
        l = strlen(t);
        if(mxl < l) mxl = l;
    }
    print();
    for(i = 1; i <= n; i ++) print(s[i]);
    print();
}