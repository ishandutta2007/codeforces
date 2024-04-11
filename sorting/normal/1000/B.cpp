#include<iostream>

using namespace std;

int a[100007];
int res[100007];

int main ()
{
    int n,i,k,best=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    for(i=1;i<=n;i++)
        cin>>a[i];

    a[0]=0;
    a[n+1]=k;

    n+=2;

    res[n-1]=0;

    for(i=n-2;i>=0;i--)
    {
        if(i&1)
            res[i]=res[i+1];
        else
            res[i]=res[i+1]+a[i+1]-a[i];
    }

    best=res[0];

    //cout<<best<<endl;

    for(i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]!=1)
        {
            if(i&1)
                best=max(best,a[n-1]-a[i]-res[i]+res[0]-res[i]-1);
            else
                best=max(best,a[n-1]-a[i]-res[i]+res[0]-res[i]+1);
        }

        //cout<<best<<endl;
    }

    cout<<best<<"\n";

    return 0;
}