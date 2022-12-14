#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    int in=x;
    if (n==1)
    {
        cout<<"YES"<<endl<<x<<endl;
    }
    else if (n==2)
    {
        if (x==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl<<0<<' '<<x<<endl;
    }
    else
    {
        for (int i=1;i<n;i++)
            a[i]=i,x^=a[i];
        if (x<n)
        {
            int j=1;
            for (j=1;j<n;j++)
            {
                if (j!=x)break;
            }
            a[j]+=(1<<18);
            a[n]=x+(1<<18);
        }
        else
            a[n]=x;
            cout<<"YES"<<endl;
            int ret=0;
        for (int i=1;i<=n;i++)
            cout<<a[i]<<' ',ret^=a[i];
        assert(ret==in);
        cout<<endl;
    }
}