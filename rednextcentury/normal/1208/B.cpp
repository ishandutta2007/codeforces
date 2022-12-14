#include <bits/stdc++.h>
using namespace std;
set<int> s;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int ret=1;
    for (int i=0;i<=n;i++)
    {
        if (s.find(a[i])!=s.end())break;
        s.insert(a[i]);
        int j;
        for (j=n;j>i;j--)
        {
            if (s.find(a[j])!=s.end())
                break;
            s.insert(a[j]);
        }
        ret=max(ret,(int)s.size());
        j++;
        while(j<=n)s.erase(a[j]),j++;
    }
    cout<<n+1-ret<<endl;
}