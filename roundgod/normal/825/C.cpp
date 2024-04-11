#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
typedef long long ll;
int n,k,a[MAXN];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int i=0,cnt=0;
    sort(a,a+n);
    ll t=k;
    while(i<n)
    {
        if(a[i]<=t) i++;
        if(a[i]>t)
        {
            if(a[i]<=2*t)
            {
                t=a[i];
                i++;
            }
            else
            {
                while(a[i]>2*t)
                {
                    t*=2;
                    cnt++;
                }
                t=a[i];
                i++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}