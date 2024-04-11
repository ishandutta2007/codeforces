#include<cstdio>
#include<algorithm>
using namespace std;
int a1,a2,a3,a4,S,n;
int main()
{
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        if(x==1)a1++;else
        if(x==2)a2++;else
        if(x==3)a3++;else
        if(x==4)a4++;
    }
    S+=a4,a4=0;
    int a13=min(a1,a3);
    S+=a13,a1-=a13,a3-=a13;
    S+=a3,a3=0;
    int a22=a2/2;
    S+=a22,a2-=a22*2;
    if(a2)
    {
        int a21=min(2,a1);
        S+=1,a1-=a21,a2=0;
    }
    int a41=a1/4;
    S+=a41,a1-=a41*4;
    if(a1)S+=1,a1=0;
    printf("%d\n",S);
    return 0;
}