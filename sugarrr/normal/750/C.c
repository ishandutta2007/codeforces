
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main() {
    int n;
    scanf("%d",&n);
    int c[n],d[n],e[n+1],i;
    for(i=0;i<=n-1;i++)scanf("%d %d",&c[i],&d[i]);
    e[n]=0;
    for(i=n-1;i>=0;i--){
        e[i]=e[i+1]-c[i];
    }
    int infflag=1;/*1infinity*/
    for(i=0;i<=n-1;i++){
        if(d[i]==2)infflag=0;
    }
    
    int maxdiv2=-21000000;
    for(i=0;i<=n-1;i++){
        if(d[i]==2 && e[i]>maxdiv2){
            maxdiv2=e[i];
        }
    }
    int ans=1899-maxdiv2;
    
    int impflag=0;/*1impoosible*/
    
    for(i=0;i<=n-1;i++){
        if(d[i]==1 &&(ans+e[i])<1900)impflag=1;
        else if(d[i]==2 && (ans+e[i])>=1900)impflag=1;
    }
    
    if(infflag==1){
        printf("Infinity");
    }else if(impflag==1){
        printf("Impossible");
    }else{
        printf("%d",ans);
    }
    return 0;
}