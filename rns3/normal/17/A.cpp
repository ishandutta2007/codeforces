///a
#include<stdio.h>
#define N 1001

int fg[N],sis[N];

int main()
{
    int n,k,tot=0,res=0;
    scanf("%d%d",&n,&k);
    for(int i=2;i<n;i++)if(fg[i]==0){
        sis[tot++]=i;
        for(int ii=i+i;ii<=n;ii+=i){
            fg[ii]=1;
        }
    }
 ///  for(int i=0;i<tot;i++)printf("%d ",sis[i]);
    for(int i=0;i<tot;i++){
        int k=sis[i]+sis[i+1]+1;
        if(k>n)break;
        if(fg[k]==0) res++;
    }
    ///printf("%d\n",res);
    if(res>=k)puts("YES");
    else puts("NO");
    return 0;
}