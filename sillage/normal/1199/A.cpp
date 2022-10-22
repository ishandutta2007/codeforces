#include<cstdio>
int n,x,y,a[110000];
int main(){
    scanf("%d%d%d",&n,&x,&y);
    for (int i=x; i<x+n; i++)  scanf("%d",&a[i]);
    for (int i=0; i<x; i++) a[i]=1e9+1;
    for (int i=x+n; i<x+n+y; i++) a[i]=1e9+1;
    for (int i=x; i<x+n; i++){
        int flag=1;
        for (int j=i-x; j<i; j++) if (a[j]<a[i]) flag=0;
        for (int j=i+1; j<=i+y; j++) if (a[j]<a[i]) flag=0;
        if (flag){
            printf("%d\n",i-x+1);
            break;
        }
    }
}