#include<cstdio>
using namespace std;

int gcd(int x,int y){
    return (y==0)?x:gcd(y,x%y);
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(k<n/2){printf("-1\n");return 0;}
    if(n==1 && k>0){printf("-1\n");return 0;}
    if(n==1){printf("1\n");return 0;}
    int x=k-n/2+1,max=1;
    printf("%d %d",x,x*2);
    for(int j=1;j<n/2;j++){
        if(max==x)max++;
        if(max==x*2)max++;
        int i=max+1;
        while(i==x || i==x*2 || gcd(max,i)>1)i++;
        printf(" %d %d",max,i);
        max=i+1;
    }
    if(n%2){
        if(max==x)max++;
        if(max==x*2)max++;
        printf(" %d",max);
    }
    printf("\n");
    return 0;
}