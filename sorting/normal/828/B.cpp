#include<iostream>
#include<stdio.h>

using namespace std;

char c[101][101];

int main ()
{
    int n,m,i,j,t=101,l=101,r=-1,b=-1,s1,s2,res=0;
    bool x=false;

    //ios::sync_with_stdio(false);

    //cin>>n>>m;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf(" %c",&c[i][0]);
        for(j=1;j<m;j++)
        {
            scanf("%c",&c[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(c[i][j]=='B')
            {
                x=true;
                if(i<t)t=i;
                if(i>b)b=i;
                if(j<l)l=j;
                if(j>r)r=j;
            }
        }
    }


    if(x==false)
    {
        cout<<"1"<<endl;
        return 0;
    }

    s1=b-t+1;
    s2=r-l+1;

    if(s2>s1)
    {
        if(n>=s2)
        {
            res+=(s2-s1)*s2;
            s1=s2;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    if(s1>s2)
    {
        if(m>=s1)
        {
            res+=(s1-s2)*s1;
            s2=s1;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    for(i=t;i<=b;i++)
    {
        for(j=l;j<=r;j++)
        {
            if(c[i][j]=='W')res++;
        }
    }

    cout<<res<<endl;

    return 0;
}