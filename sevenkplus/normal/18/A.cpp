#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[6];
inline bool Right()
{
    return ((a[0]!=a[2])||(a[1]!=a[3]))&&((a[0]!=a[4])||(a[1]!=a[5]))&&((a[2]!=a[4])||(a[3]!=a[5]))&&(
        ((a[2]-a[0])*(a[4]-a[0])+(a[3]-a[1])*(a[5]-a[1])==0)||
        ((a[4]-a[2])*(a[0]-a[2])+(a[5]-a[3])*(a[1]-a[3])==0)||
        ((a[0]-a[4])*(a[2]-a[4])+(a[1]-a[5])*(a[3]-a[5])==0));
}
string Calc()
{
    if(Right())
        return "RIGHT";
    for(int i=0;i<6;i++)
    {
        a[i]++;
        if(Right())
            return "ALMOST";
        a[i]-=2;
        if(Right())
            return "ALMOST";
        a[i]++;
    }
    return "NEITHER";
}
int main()
{
    for(int i=0;i<6;i++)
        scanf("%d",a+i);
    puts(Calc().c_str());
    return 0;
}