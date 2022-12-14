#include<bits/stdc++.h>
using namespace std;
int n,m;
void Neven()
{
    cout<<0<<endl;
    int x=1,y=1;
    cout<<x<<' '<<y<<endl;
    for (int i=2;i<=n;i++)
        cout<<++x<<' '<<y<<endl;
    for (int i=n;i>=1;i--)
    {
        if (i%2==0)
        {
            for (int j=2;j<=m;j++)
                cout<<i<<' '<<j<<endl;
        }
        else
        {
            for (int j=m;j>=2;j--)
                cout<<i<<' '<<j<<endl;
        }
    }
    cout<<1<<' '<<1<<endl;
}
void Meven()
{
    cout<<0<<endl;
    int x=1,y=1;
    cout<<x<<' '<<y<<endl;
    for (int i=2;i<=m;i++)
        cout<<x<<' '<<++y<<endl;
    for (int i=m;i>=1;i--)
    {
        if (i%2==0)
        {
            for (int j=2;j<=n;j++)
                cout<<j<<' '<<i<<endl;
        }
        else
        {
            for (int j=n;j>=2;j--)
                cout<<j<<' '<<i<<endl;
        }
    }
    cout<<1<<' '<<1<<endl;
}
void Odd()
{
    cout<<1<<endl;
    cout<<n<<' '<<m<<' '<<1<<' '<<1<<endl;
    for (int i=1;i<=n;i++)
    {
        if (i%2)
        {
            for (int j=1;j<=m;j++)
                cout<<i<<' '<<j<<endl;
        }
        else
        {
            for (int j=m;j>=1;j--)
                cout<<i<<' '<<j<<endl;
        }
    }
    cout<<1<<' '<<1<<endl;
}
int main()
{
    cin>>n>>m;
    if (n==1)
    {
        if (m==2)
        {
            cout<<0<<endl;
            cout<<"1 1\n1 2\n1 1\n";
        }
        else
            Odd();
    }
    else if (m==1)
    {
        if (n==2)
        {
            cout<<0<<endl;
            cout<<"1 1\n2 1\n1 1\n";
        }
        else
            Odd();
    }
    else if (n%2==0)
        Neven();
    else if (m%2==0)
        Meven();
    else
        Odd();
}