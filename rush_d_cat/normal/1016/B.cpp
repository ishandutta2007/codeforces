#include <iostream>
using namespace std;
int n,m,q,ok[5002];
char s[5002],t[5002];
int main() {
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s",s+1,t+1);
    for(int i=1;i<=n-m+1;i++){
        ok[i]=1;
        for(int j=i;j<=i+m-1;j++){
            if(s[j]!=t[j-i+1]) ok[i]=0;
        }
        //printf("%d %d\n", i, ok[i]);
    }
    for(int i=1;i<=n;i++) ok[i]=ok[i-1]+ok[i];
    while(q--) {
        int l,r; scanf("%d%d",&l,&r);
        if(r-l+1<m) printf("0\n");
        else if(n<m) printf("0\n");
        else printf("%d\n", max(ok[r-m+1]-ok[l-1],0));
    }
}