#include <bits/stdc++.h>
using namespace std;
#define ll long long
multiset<int> s;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],s.insert(a[i]);
    int num=0;
    for (int i=1;i<=n;i++)
    {
        if (s.upper_bound(a[i])!=s.end())
        {
            int x = *s.upper_bound(a[i]);
            s.erase(s.upper_bound(a[i]));
            a[i]=x;
            num++;
        }
        //cout<<a[i]<<' ';
    }
    cout<<num<<endl;

}