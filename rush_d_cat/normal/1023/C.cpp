#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;
int n,k;
char s[N];
int nex[N], stk[N], top, d[N];
int main() {
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++) {
        if(s[i]=='(') stk[++top] = i;
        if(s[i]==')') {
            nex[stk[top]] = i; top --;
        }
    }
    int del = (n - k) / 2;
    for(int i=1;i<=n;i++) {
        if(s[i]=='(' && del) {
            del --; d[i]=1; d[nex[i]]=1;
        }
    }
    for(int i=1;i<=n;i++) {
        if(d[i]==0) printf("%c", s[i]);
    }
    printf("\n");
}