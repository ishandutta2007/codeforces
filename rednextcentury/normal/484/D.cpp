#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<long long> mn,mx;
long long a[1000001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    mn.insert(a[1]);
    mx.insert(a[1]);
    for (int i=1;i<=n;i++)
    {
        long long cur = max(a[i]-*mn.begin(),-a[i]+*mx.rbegin());
        mn.insert(-cur+a[i+1]);
        mx.insert(cur+a[i+1]);
        if (i==n)cout<<cur<<endl;
    }
}