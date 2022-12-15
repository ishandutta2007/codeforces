#include<iostream>
#include<algorithm>

using namespace std;

int a[10001];
int sum=0;

int main ()
{
    int n,i;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    sort(a,a+n);

    for(i=0;i<n && sum*2<9*n;i++)
        sum+=5-a[i];

    cout<<i<<endl;

    return 0;
}