///a
#include<stdio.h>

int n,tot;

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int ap=i,pr=0;
        for(int j=2;ap!=1;j++){
            if(ap%j)continue;
            pr++;
            while(ap%j==0)ap/=j;
        }
        if(pr==2)tot++;
    }
    printf("%d\n",tot);

    return 0;
}