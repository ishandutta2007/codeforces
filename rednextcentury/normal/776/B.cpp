# include <bits/stdc++.h>
using namespace std;
int prime[1000002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=2;i<=1000000;i++)
    {
        if (prime[i])
            continue;
        for (int j=i+i;j<=1000000;j+=i)
            prime[j]=1;
    }
    int n;
    cin>>n;
    if (n==1)
        cout<<1<<endl<<1<<endl;
    else if (n==2)
        cout<<1<<endl<<1<<' '<<1<<endl;
    else
    {
        cout<<2<<endl;
        for (int i=2;i<=n+1;i++)
            cout<<prime[i]+1<<' ';
        cout<<endl;
    }
}