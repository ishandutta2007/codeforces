#include <bits/stdc++.h>

using namespace std;
int a[3000];
int GCD(int x,int y)
{
    if (x==0)return y;
    if (y==0)return x;
    if (x%y==0)return y;
    if (y%x==0)return x;
    return GCD(y%x,x);
}

int main()
{
    int n;
    cin>>n;
    int one=0;
    int ret=n+1;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]==1)one++;
        int x=a[i];
        int mn=1;
        for (int j=i-1;j>=0;j--)
        {
            x=GCD(x,a[j]);
            if (x==1)break;
            mn++;
        }
        if (x==1)
            ret=min(ret,mn);
    }
    if (one)
        cout<<n-one<<endl;
    else if (ret<n+1)
        cout<<n+ret-1<<endl;
    else cout<<-1<<endl;
}