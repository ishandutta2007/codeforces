#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int a[N],res[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        res[i]=0;
    }
    for (int i=n; i>=1; i--)
    {
        while (a[i]!=i)
        {
            int t=a[1];
            for (int j=1; j<i; j++)
                a[j]=a[j+1];
            a[i]=t;
            res[i]++;
        }
    }
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while (t--) up();
}