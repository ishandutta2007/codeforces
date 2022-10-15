#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,a,b;
int main()
{
    scanf("%d %d %d",&n,&a,&b);
    int x=a,y=0,z=b,cnt=0;
    for(int i=0;i<n;i++)
    {
        int p;
        scanf("%d",&p);
        if(p==1)
        {
            if(x==0)
            {
                if(z==0)
                {
                    if(y==0)
                    {
                        cnt++;
                    }
                    else
                    {
                        y--;
                    }
                }
                else
                {
                    z--;
                    y++;
                }
            }
            else
            {
                x--;
            }
        }
        else
        {
            if(z==0)
            {
                cnt+=2;
            }
            else
            {
                z--;
            }
        }
    }
        printf("%d\n",cnt);
        return 0;
}