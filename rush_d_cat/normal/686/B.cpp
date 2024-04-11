#include<iostream>
#include<cstdio>
using namespace std;
typedef __int64 ll;
ll a[100+10];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=2;i--)
    {
        for(int j=2;j<=i;j++)
        {
            if(a[j]<a[j-1])
            {
                ll tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                cout<<(j-1)<<" "<<j<<endl;
            }
        }
    }
    return 0;
}