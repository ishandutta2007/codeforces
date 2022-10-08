#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=min(a,c);i++)
        if((c-(ll)i*1000000000%c)%c>b){printf("1 %09d\n",i);return 0;}
    puts("2");
    return 0;
}