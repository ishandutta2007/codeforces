#include<bits/stdc++.h>
using namespace std;

#define N 200500

char c[N];

int main(){
    int i, len;
    gets(c);
    len = strlen(c);
    for(i = 0; i < len; i ++) printf("%c", c[i]);
    for(i = len - 1; i >= 0; i --) printf("%c", c[i]);
    puts("");
}