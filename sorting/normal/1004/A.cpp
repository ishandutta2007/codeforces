#include<iostream>
#include<algorithm>

using namespace std;

int a[101];

int main ()
{
    int n,d,res=2,i;

    cin>>n>>d;

    for(i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    for(i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]>2*d)
            res+=2;
        else
        {
            if(a[i+1]-a[i]==2*d)
                res++;
        }

    }

    cout<<res<<"\n";

    return 0;
}