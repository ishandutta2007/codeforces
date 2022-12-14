#include<bits/stdc++.h>
using namespace std;
long double x[100000];
long double y[100000];
long double R;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>R;
    for (int i=0;i<n;i++)
        cin>>x[i];
    for (int i=0;i<n;i++)
    {
        long double ans=R;
        for (int j=0;j<i;j++)
        {
            long double l=y[j];
            long double r=2002000.0;
            long double ret=-1;
            for (int op=0;op<60;op++)
            {
                long double mid = (l+r)/2.0;
                if ((hypot(x[i]-x[j],mid-y[j])<=2*R))
                    ret=mid,l=mid;
                else
                    r=mid;
            }
            long double cur = ret;
            if (cur<0)continue;
            else ans=max(cur,ans);
        }
        y[i]=ans;
    }
    for (int i=0;i<n;i++)
        cout<<setprecision(10)<<fixed<<y[i]<<' ';
    cout<<endl;

}