#include <stdio.h>
int main(){
    int i,n,m;
    //freopen("in.txt","r",stdin);
    scanf("%d %d\n",&n,&m);
    if(n>m+1 || (m-2)>2*n) {puts("-1");return 0;}
    if(n==m+1){for(i=0;i<m;i++) printf("01");printf("0");return 0;}
    if(n==m) {for(i=0;i<m;i++) printf("01");return 0;}
    if(m==2*n+2) {for(i=0;i<n;i++) printf("110");printf("11");return 0;}
    if(m==2*n+1) {for(i=0;i<n;i++) printf("110");printf("1");return 0;}
    if(m==2*n) {for(i=0;i<n;i++) printf("110");return 0;}
    for(i=0;i<m-n;i++) printf("110");
    for(i=0;i<2*n-m;i++) printf("10");
    return 0;
}