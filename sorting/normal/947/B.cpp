#include<iostream>

using namespace std;

long long v[100005],t[100005];
long long res[100005];
long long res2[100005],n;
long long f[100005];

int binSearch(long long ind)
{
    long long l,r,mid;

    l=ind-1;
    r=n;

    while(l!=r)
    {
        mid=(l+r+1)/2;

        if(t[mid]-t[ind-1]<=v[ind])
            l=mid;
        else
            r=mid-1;
    }


    return l;
}

int main ()
{
    long long i,x;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>v[i];

    for(i=1;i<=n;i++)
        cin>>t[i];

    for(i=2;i<=n;i++)
    {
        t[i]+=t[i-1];
    }

    for(i=1;i<=n;i++)
    {
        x=binSearch(i);

        //cout<<x<<endl;

        res[i]+=1;
        res[x+1]+=-1;
        res2[x+1]+=v[i]-t[x]+t[i-1];
        //cout<<v[i]-t[x]+t[i-1]<<endl;
    }

    for(i=1;i<=n;i++)
    {
        res[i]+=res[i-1];
        f[i]=res[i]*(t[i]-t[i-1])+res2[i];
    }

    for(i=1;i<n;i++)
        cout<<f[i]<<" ";
    cout<<f[i]<<endl;

    return 0;
}