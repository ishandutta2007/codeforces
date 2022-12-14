#include<bits/stdc++.h>
using namespace std;
int a[100010];
long long num[10004];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    long long ret=0;
    for (int i=0;i<=10000;i++)
    {
        for (int j=i;j<=10000;j++)
        {
            if (__builtin_popcount(i^j)==k)
            {
                if (i==j)ret+=num[i]*(num[i]-1)/2;
                else ret+=num[i]*num[j];
            }
        }
    }
    cout<<ret<<endl;
}