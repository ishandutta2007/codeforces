#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    while(1)
    {
        int aa=gcd(a,n);
        if(aa>n){puts("1");return 0;}
        n-=aa;
        int bb=gcd(b,n);
        if(bb>n){puts("0");return 0;}
        n-=bb;
    }
    return 0;
}