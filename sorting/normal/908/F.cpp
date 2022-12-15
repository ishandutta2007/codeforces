#include<iostream>

using namespace std;

#define MAXI 20000000000000

long long p[300001];
short c[300001];
long long g[300001],cnt;

long long res;

int main ()
{
    long long n,i,j,mini,pr,r;
    char ch;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>p[i]>>ch;
        if(ch=='G')
        {
            c[i]=0;
            g[cnt]=i;
            cnt++;
        }
        if(ch=='R')c[i]=1;
        if(ch=='B')c[i]=2;
    }

    if(cnt==0)
    {
        g[0]=-1;
    }

    for(i=0;i<cnt-1;i++)
    {
        r=0;
        r+=p[g[i+1]]-p[g[i]];

        //cout<<res<<endl;

        if(g[i+1]-g[i]==1)
        {
            res+=r;
            continue;
        }

        mini=-1;

        pr=g[i];

        for(j=g[i]+1;j<=g[i+1];j++)
        {
            if(c[j]==1 || c[j]==0)
            {
                if(p[j]-p[pr]>mini)mini=p[j]-p[pr];
                pr=j;
            }
        }

        r+=p[g[i+1]]-p[g[i]]-mini;

        //cout<<mini<<endl;

        //cout<<res<<endl;

        mini=-1;
        pr=g[i];

        for(j=g[i]+1;j<=g[i+1];j++)
        {
            if(c[j]==2|| c[j]==0)
            {
                if(p[j]-p[pr]>mini)mini=p[j]-p[pr];
                pr=j;
            }
        }

        r+=p[g[i+1]]-p[g[i]]-mini;

        r=min(r,2*(p[g[i+1]]-p[g[i]]));


        res+=r;
    }

    if(cnt==0)
    {
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            {
                pr=i;
                break;
            }
        }
        for(i=n-1;i>=0;i--)
        {
            if(c[i]==1)
            {
                res+=p[i]-p[pr];
                break;
            }
        }

        for(i=0;i<n;i++)
        {
            if(c[i]==2)
            {
                pr=i;
                break;
            }
        }
        for(i=n-1;i>=0;i--)
        {
            if(c[i]==2)
            {
                res+=p[i]-p[pr];
                break;
            }
        }

        cout<<res<<endl;

        return 0;
    }

    for(i=0;i<g[0];i++)
    {
        if(c[i]==1)
        {
            res+=p[g[0]]-p[i];
            break;
        }
    }

    for(i=0;i<g[0];i++)
    {
        if(c[i]==2)
        {
            res+=p[g[0]]-p[i];
            break;
        }
    }

    if(cnt!=0)
    {
        for(i=n-1;i>g[cnt-1];i--)
        {
            if(c[i]==1)
            {
                res+=p[i]-p[g[cnt-1]];
                break;
            }
        }

        for(i=n-1;i>g[cnt-1];i--)
        {
            if(c[i]==2)
            {
                res+=p[i]-p[g[cnt-1]];
                break;
            }
        }
    }


    cout<<res<<endl;

    return 0;
}