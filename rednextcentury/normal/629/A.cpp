#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
long long r[1000];
long long c[1000];
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            char x;
            cin>>x;
            if (x=='C')
                r[i]++,c[j]++;
        }
    }
    for (int i=0;i<n;i++)
    {
        ans+=(r[i]*(r[i]-1))/2;
        ans+=(c[i]*(c[i]-1))/2;
    }
    cout<<ans<<endl;
}