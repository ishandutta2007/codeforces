#include<bits/stdc++.h>
using namespace std;
long long a[1000003];
int n;
long long l[1000003];
long long r[1000003];
long long ret=0;
void solve()
{
    stack<int> pre;
    stack<int> suf;
    for (int i=1;i<=n;i++)
    {
        while(!pre.empty() && a[pre.top()]<=a[i])
            pre.pop();
        if (pre.empty())
            l[i]=0;
        else
            l[i]=pre.top();
        pre.push(i);
    }
    for (int i=n;i>=1;i--)
    {
        while(!suf.empty() && a[suf.top()]<a[i])
            suf.pop();
        if (suf.empty())
            r[i]=n+1;
        else
            r[i]=suf.top();
        suf.push(i);
    }
    for (int i=1;i<=n;i++)
    {
        long long left=i-l[i],right=r[i]-i;
        ret+=left*right*a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    solve();
    for (int i=1;i<=n;i++)
        a[i]=-a[i];
    solve();
    cout<<ret<<endl;
}