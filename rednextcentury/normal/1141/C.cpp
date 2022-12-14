#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long mn=0;
    long long sum=0;
    for (int i=1;i<n;i++)
    {
        cin>>b[i];
        sum+=b[i];
        mn=min(mn,sum);
    }
    a[1]=1-mn;
    for (int i=1;i<n;i++)
        a[i+1]=a[i]+b[i];
    set<int> s;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>n || a[i]<1)
        {
            cout<<-1<<endl;
            return 0;
        }
        s.insert(a[i]);
    }
    if (s.size()==n)
    {
        for (int i=1;i<=n;i++)
            cout<<a[i]<<' ';
    }
    else cout<<-1<<endl;
}