#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long divs[1000000];
long long p[1000000];
long long num[1000000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                divs[a[i]/j]++;
                if(a[i]/j!=j)divs[j]++;
            }
        }
    }
    p[0]=1;
    for(int i=1;i<=100000;i++)
        p[i]=(p[i-1]*2)%1000000007;
    for(int i=100000;i>=2;i--)
    {
        if(divs[i])
        {
            num[i]=(p[divs[i]]-1+1000000007)%1000000007;
            for(int j=2;j<=100000/i;j++)
                num[i]=(num[i]-num[i*j]+1000000007)%1000000007;
        }
    }
    long long ans=p[n];
    for(int i=2;i<=100000;i++)
        ans=(ans-num[i]+1000000007)%1000000007;
    cout<<(ans-1+1000000007)%1000000007<<endl;
    return 0;
}