#include<iostream>
#include<algorithm>

using namespace std;

long long a[3];

int main ()
{
    long long res=0,p;

    cin>>a[0]>>a[1]>>a[2];

    sort(a,a+3);

    res=(a[0]+a[1]+a[2]);
    p=res%3;
    res/=3;

    if(a[2]-2*res>p)
    {
        res-=a[2]-2*res-p;
    }

    cout<<res<<endl;

    return 0;
}