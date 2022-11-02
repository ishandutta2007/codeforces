#include <stdio.h>
int a,b,m,n;
void cw(){
    int bb=n+1-a;
    a=b;b=bb;
    int mm=m;m=n;n=mm;
    return;
}
void hr(){
    b=m+1-b;
    return ;
}
void acw(){
    int aa=m+1-b;
    b=a;a=aa;
    int mm=m;m=n;n=mm;
    return ;
}
int main(){
    int x,y,z,r,s,p,i,j;
    //freopen("in.txt","r",stdin);
    scanf("%d %d %d %d %d %d\n",&n,&m,&x,&y,&z,&p);
    x%=4;y%=2;z%=4;
    r=n;s=m;
    for(i=0;i<p;i++){
        n=r;m=s;
        scanf("%d %d\n",&a,&b);
        for(j=0;j<x;j++) cw();
        for(j=0;j<y;j++) hr();
        for(j=0;j<z;j++) acw();
        printf("%d %d\n",a,b);
    }
    return 0;
}