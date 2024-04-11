#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define M 300001
int n,m;
char s[M];
int f[30];
char a[10],b[10];
int x[M],y[M];

int main() {

    scanf("%d %d",&n,&m);
    scanf("%s",s);
    for(int i=0;i<m;i++) {
        scanf("%s %s",a,b);
        x[i] = a[0] - 'a';
        y[i] = b[0] - 'a';
    }
    for(int i=0;i<26;i++) {
        int tp = i;
        for(int j=0;j<m;j++) {
            if(x[j] == tp) tp = y[j];
            else if(y[j] == tp) tp = x[j];
        }
        f[i] = tp;
    }
    for(int i=0;i<n;i++) printf("%c",'a'+f[s[i]-'a']);puts("");
}