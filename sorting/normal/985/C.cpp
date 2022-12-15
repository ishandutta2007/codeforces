#include<iostream>
#include<algorithm>

using namespace std;

const int maxi=100000;

long long a[maxi+7];
long long m,n,k;

long long binarySearch(long long x)
{
    long long l=0,r=m-1,mid;

    while(l!=r)
    {
        mid=(l+r+1)/2;

        if(a[mid]<=x)
            l=mid;
        else
            r=mid-1;
    }

    return l;
}

int main ()
{
    long long i,res=0,p,l,pr;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>l;

    m=n*k;

    for(i=0;i<m;i++)
        cin>>a[i];

    sort(a,a+m);

    pr=0;

    if(a[n-1]-a[0]>l)
    {
        cout<<"0"<<endl;
        return 0;
    }

    p=binarySearch(a[0]+l);

    for(i=0;i<n;i++)
    {
        //cout<<pr<<endl;

        pr=i*k;

        if(p-(n-i-1)<pr)
            pr=p-(n-i-1);

        res+=a[pr];
    }

    cout<<res<<endl;

    return 0;
}