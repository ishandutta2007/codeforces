#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;
int n,m;
char s[N],t[N];
int main() {
    scanf("%d%d%s%s",&n,&m,s+1,t+1);
    if(n>m+1) {
        return !printf("NO\n");
    }
    int p=-1;
    for(int i=1;i<=n;i++) {
        if(s[i]=='*') {
            p=i; break;
        }
    }
    bool ok = 1;
    for(int i=1;i<p;i++) if(s[i]!=t[i]) ok=0;
    for(int i=n;i>p;i--) if(s[i]!=t[m-(n-i)]) ok=0;
    printf("%s\n", ok?"YES":"NO");
}