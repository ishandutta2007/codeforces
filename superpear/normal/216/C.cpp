#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>

#define maxlongint 2147483647;

using namespace std;

int maxn=2200,ans=0,a[2500],e[2100000],key[2500],m,n,k;

void hire(int x)
{
    ans++;
    e[ans]=x;
    while (true)
    {
        if (x+n-1>=maxn)
        {
            for (int i=x;i<=maxn;i++)
            {
                a[i]++;
                if (i!=maxn) key[i]=1;
            }
            break;
        }
        else
        {
            for (int i=x;i<=x+n-1;i++)
            {
                a[i]++;
                if (i!=x+n-1) key[i]=1;
            }
            x+=m+n;
        }
    }
}

int main()
{
    int q;
    memset(a,0,sizeof(a));
    memset(e,0,sizeof(e));
    memset(key,0,sizeof(key));
    cin>>n>>m>>k;
    for (int i=1;i<=maxn;i++)
    {
        if (a[i]<k)
        {
            q=k-a[i];
            for (int j=1;j<=q;j++) hire(i);
        }
        else
        {
            if ((i<maxn)&&(key[i]==0)) hire(i);
        }
    }
    cout<<ans<<endl;
    for (int i=1;i<ans;i++) cout<<e[i]<<" ";
    cout<<e[ans]<<endl;
    return 0;
}