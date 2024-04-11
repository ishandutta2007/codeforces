#include<stdio.h>
int x;
int search(int a){
    int t=0;
    if(!a)return 0;
    if(a<0)a*=-1;
    while(a){
            t+=a/x;
            a=a-a/x*x;
            x=a%x;
    }
    return t;
}
int main(){
    int n,sum,ans,i;
    int a[1000];
   // freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&x);
    for(i=0,sum=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
    }
    ans=search(sum);
    printf("%d\n",ans);
    return 0;
}