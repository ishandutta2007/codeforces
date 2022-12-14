# include <iostream>
# include <cmath>
# include <stdio.h>
#include <algorithm>
using namespace std;
int hp1,hp2,atk1,atk2,def1,def2;
bool win()
{
    if (atk1<=def2)
        return 0;
    if (atk2<=def1)
        return 1;
    int pow1=atk1-def2;
    int pow2=atk2-def1;
    int need;
    if (hp2%pow1==0)
        need=hp2/pow1;
    else
        need=(hp2/pow1)+1;
    int need2=hp1/pow2;
    if (hp1%pow2!=0)
        need2++;
    if (need<need2)
        return 1;
    return 0;
}
int main()
{
    cin>>hp1>>atk1>>def1;
    cin>>hp2>>atk2>>def2;
    int h,a,d;
    cin>>h>>a>>d;
    int ans=10000000;
    for (int i=0;i<=5001;i++)
    {
        for (int x=0;x<=200;x++)
        {
            for (int j=0;j<=101;j++)
            {
                int now=i*h+x*a+j*d;
                hp1+=i;
                atk1+=x;
                def1+=j;
                if (win() && now<ans)
                    ans=now;
                hp1-=i;
                atk1-=x;
                def1-=j;
            }
        }
    }
    cout<<ans<<endl;
}