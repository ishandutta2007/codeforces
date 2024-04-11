#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
typedef long long ll;
int n;
ll y[MAXN];
bool f;
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&y[i]);
    ll k;
    ll x1,y1,x0,y0;
    f=true;
    for(int i=2;i<n;i++)
    {
        if(i==2) k=y[i]-y[1];
        else if(k*(i-1)!=y[i]-y[1]){f=false; break;}
    }
    if(f)
    {
        if(k!=y[1]-y[0])
        {
            printf("Yes\n");
            return 0;
        }
    }
    for(int i=1;i<n;i++)
    {
        f=true;
        memset(used,false,sizeof(used));
        used[i]=true;
        for(int j=i+1;j<n;j++)
            if((y[j]-y[0])*i==(y[i]-y[0])*j)
                used[j]=true;
        int cnt=0;
        for(int j=1;j<n;j++)
        {
            if(!used[j])
            {
                if((y[j]-y[0])*i==(y[i]-y[0])*j){f=false; break;}
                if(cnt==0)
                {
                    x0=j,y0=y[j];
                    cnt++;
                }
                else
                {
                    if(cnt==1)
                    {
                        x1=j,y1=y[j];
                        cnt++;
                    }
                    else
                    {
                        if((y[j]-y0)*(x1-x0)!=(y1-y0)*(j-x0))
                        {
                            f=false;
                            break;
                        }
                    }
                }
            }
        }
        if(f)
        {
           if((y[i]-y[0])*(x1-x0)==(y1-y0)*i||cnt==1)
           {
                printf("Yes\n");
                return 0;
           }
        }
    }
    printf("No\n");
    return 0;
}