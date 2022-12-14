#include <bits/stdc++.h>
using namespace std;
int can1[1000000];
int can2[1000000];
pair<long long,int> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,x1,x2;
    cin>>n>>x1>>x2;
    for (int i=1;i<=n;i++)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        can1[i]=can1[i+1];
        can2[i]=can2[i+1];
        if (a[i].first*(n-i+1)>=x1)
            can1[i]=i;
        if (a[i].first*(n-i+1)>=x2)
            can2[i]=i;
    }
    for (int i=1;i<=n;i++)
    {
        long long need1 = x1/a[i].first+((x1%a[i].first)>0);
        long long need2 = x2/a[i].first+((x2%a[i].first)>0);
        if (need1<=n && can2[i+need1])
        {
            cout<<"Yes"<<endl;
            cout<<need1<<' ';
            cout<<n-can2[i+need1]+1<<endl;
            for (int j=i;j<i+need1;j++)
                cout<<a[j].second<<' ';
            cout<<endl;
            for (int j=can2[i+need1];j<=n;j++)
                cout<<a[j].second<<' ';
            cout<<endl;
            return 0;
        }
        if (need2<=n && can1[i+need2])
        {
            cout<<"Yes"<<endl;
            cout<<n-can1[i+need2]+1<<' '<<need2<<endl;
            for (int j=can1[i+need2];j<=n;j++)
                cout<<a[j].second<<' ';
            cout<<endl;
            for (int j=i;j<i+need2;j++)
                cout<<a[j].second<<' ';
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}