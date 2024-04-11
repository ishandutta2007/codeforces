#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int a[101];

int main ()
{
    int n,i,sum1=0,sum2=0;

    cin>>n;

    for(i=0;i<n/2;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n/2);

    for(i=0;i<n/2;i++)
    {
        sum1+=abs(a[i]-i*2-1);
        sum2+=abs(a[i]-2*i-2);
    }

    cout<<min(sum1,sum2)<<endl;

    return 0;
}