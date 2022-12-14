# include <bits/stdc++.h>
using namespace std;
long double a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long double ans=0;
    for (int i=n-1;i>=0;i--)
    {
        long double cur=0;
        for (int j=i;j<n;j++)
        {
            long double now=a[j];
            for (int x=i;x<n;x++)
            {
                if (x==j)
                    continue;
                now*=1-a[x];
            }
            cur+=now;
        }
        ans=max(ans,cur);
    }
    cout<<setprecision(9)<<ans<<endl;
}