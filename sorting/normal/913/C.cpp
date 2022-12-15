#include<iostream>

using namespace std;

#define MAXI 1000000000000000000

long long c[31],d[31],e[31];

int main ()
{
    long long n,l,i,st,k,st2;
    long long res=0,mini,j,res2=MAXI;

    cin>>n>>l;

    for(i=0;i<n;i++)
    {
        cin>>c[i];
    }

    for(i=0;i<n;i++)
    {
        mini=(1<<(i-0))*c[0];
        k=1<<i;
        for(j=1;j<=i;j++)
        {
            if((1<<(i-j))*c[j]<mini)
            {
                mini=(1<<(i-j))*c[j];
                k=1<<i;
            }
        }
        for(j;j<n;j++)
        {
            if(c[j]<mini)
            {
                mini=c[j];
                k=1<<j;
            }
        }
        //cout<<mini<<" "<<k<<endl;
        d[i]=mini;
        e[i]=k;
    }
    while(l>0)
    {
        st=1;
        for(i=0;i<n;i++)
        {
            if(st>l)break;
            st*=2;
        }
        i--;
        //cout<<i<<" "<<l<<endl;
        if(i!=n-1)
        {
            res2=min(res2,res+d[i+1]);
            //cout<<res2<<endl;
        }
        if(e[i]>=l)
        {
            res+=d[i];
            break;
        }


        res+=d[i]*(l/e[i]);
        l%=e[i];
    }

    cout<<min(res,res2)<<endl;

    return 0;
}