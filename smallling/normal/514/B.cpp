#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

double k;
int n,x,y,x0,y0,ans,deltax,deltay,flag,o;
set<pair<int,int> >a;

int gcd(int a,int b)
{
    if(a%b)return gcd(b,a%b);
    return b;
}

int main()
{
    scanf("%d%d%d",&n,&x0,&y0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        deltax=x0-x;
        deltay=y0-y;
        if(deltax==0)a.insert(make_pair(0,1));
        else if(deltay==0)a.insert(make_pair(1,0));
        else
        {
            o=gcd(abs(deltax),abs(deltay));
            deltax/=o;
            deltay/=o;
            if(deltax<0)deltax=-deltax,deltay=-deltay;
            a.insert(make_pair(deltax,deltay));
        }
    }
    printf("%d",a.size());
}