#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
bool can(int x)
{
    for(int i=2;i<=15;i++)
    {
        int y=(int)exp(log(x)/i);
        for(int c=max(1,y-5);c<=y+5;c++)
        {
            int x1=x;bool F=1;
            for(int j=0;j<i;j++)
                if(x1%c!=0){F=0;break;}else x1/=c;
            if(F&&x1==1)return 0;
        }
    }
    return 1;
}
const int SG[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
int main()
{
    scanf("%d",&n);int Sn=n,S=0;
    for(int i=2;i*i<=n;i++)
        if(can(i))
        {
            int n1=n,t=0;
            while(n1>=i)n1/=i,t++;
            Sn-=t;
            S^=SG[t];
        }
    S^=(Sn&1);
    puts(S?"Vasya":"Petya");
    return 0;
}