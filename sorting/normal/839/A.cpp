#include<iostream>
#include<algorithm>

using namespace std;

int a[101];

int main ()
{
    int n,k,i,sum=0,cand=0;

    cin>>n>>k;

    for(i=1;i<=n;i++)cin>>a[i];

    for(i=1;i<=n;i++)
    {
        sum+=a[i];
        cand+=min(8,sum);
        sum-=min(8,sum);
        if(cand>=k)
        {
            break;
        }
    }

    if(i>n)
    {
        cout<<"-1"<<endl;
    }
    else cout<<i<<endl;

    return 0;
}