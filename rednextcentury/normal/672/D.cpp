#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    long long num=k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    bool ok=1;
    for (int i=n-1;i>0;i--)
    {
        long long need = (a[i]-a[i-1]);
        if (need*(n-i) <= num)
        {
            num-=need*(n-i);
        }
        else
        {
            long long can = num/(n-i);
            a[i]-=can;
            num=num%(n-i);
            for (int j=i+1;j<n;j++)
                a[j]=a[i];
            int j=i;
            while(num)
            {
                num--;
                a[j]--;
                j++;
            }
            ok=0;
            break;
        }
    }
    if (ok)
    {
        for (int i=1;i<n;i++)
            a[i]=a[0];
    }
    num=k-num;
    ok=1;
    for (int i=0;i+1<n;i++)
    {
        long long need = (a[i+1]-a[i]);
        if (need*(i+1) <= num)
        {
            num-=need*(i+1);
        }
        else
        {
            long long can = num/(i+1);
            a[i]+=can;
            num=num%(i+1);
            for (int j=i-1;j>=0;j--)
                a[j]=a[i];
            int j=i;
            while(num)
            {
                num--;
                a[j]++;
                j--;
            }
            ok=0;
            break;
        }
    }
    if (ok)
    {
        for (int i=0;i+1<n;i++)
            a[i]=a[n-1];
    }
    int ret;
    if (num>0 && num%n!=0)ret=1;
    else ret=a[n-1]-a[0];
    cout<<ret<<endl;
}