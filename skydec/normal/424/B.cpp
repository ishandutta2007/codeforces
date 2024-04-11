#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct city
{
    long x,y,k;
}data[1005];
long n,s;
bool cmp(city a,city b){return a.x*a.x+a.y*a.y<=b.x*b.x+b.y*b.y;}
int main()
{
    scanf("%ld%ld",&n,&s);
    for(long i=1;i<=n;i++)scanf("%ld%ld%ld",&data[i].x,&data[i].y,&data[i].k);
    sort(data+1,data+1+n,cmp);
    for(long i=1;i<=n;i++)
    {
        s+=data[i].k;
        if(s>=1000000)
        {
            printf("%.7lf\n",sqrt(data[i].x*data[i].x+data[i].y*data[i].y));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}