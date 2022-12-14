#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    long long n,k;
    cin>>n>>k;
    int num=0;
    long long i=1;
    for (i=1;i*i<n;i++)
    {
        if (n%i==0)
            num++;
    }
    int x=(i*i==n);
    if (x && k==num+1)
        cout<<i<<endl;
    else if (k>num*2+x)
        cout<<-1<<endl;
    else
    {
        int l=1,r=num*2+x;
        for (i=1;i*i<n;i++)
        {
            if (n%i==0)
            {
                if (k==l)
                    cout<<i<<endl;
                else if (k==r)
                    cout<<n/i<<endl;
                else{
                    l++,r--;
                    continue;
                }
                return 0;
            }
        }
    }

}