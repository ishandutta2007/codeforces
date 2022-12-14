#include<bits/stdc++.h>

using namespace std;
pair<int,int> a[1000000];
pair<int,int> ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        ret[i].first=a[i].second;
        ret[i].second=a[i].first/2+a[i].first%2;
        k-=ret[i].second;
    }
    if (k<0)
        cout<<-1<<endl;
    else
    {
        for (int i=n-1;i>=0;--i)
        {
            if (k>a[i].first-ret[i].second)
                k-=a[i].first-ret[i].second,ret[i].second=a[i].first;
            else
                ret[i].second+=k,k=0;
        }
        sort(ret,ret+n);
        for (int i=0;i<n;i++)
            cout<<ret[i].second<<' ';
        cout<<endl;
    }
}