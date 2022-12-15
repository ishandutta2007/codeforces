#include<iostream>
#include<algorithm>

using namespace std;

int a[1000];

int main ()
{
    int n,k,i,res=0;

    cin>>n>>k;

    for(i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);

    for(i=0;i<n;i++)
    {
        while(k*2<a[i])
        {
            k=2*k;
            res++;
        }
        if(a[i]>k)k=a[i];
    }

    cout<<res<<endl;

    return 0;
}