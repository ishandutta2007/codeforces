#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N],b[N];
int main()
{
    int n;
    cin>>n;
    int l=INT_MAX,r=INT_MIN;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i]>>b[i];
            l=min(l,a[i]);
            r=max(r,b[i]);
        }
    for (int i=1; i<=n; i++)
    {
        if (l==a[i]&&r==b[i]) {cout<<i<<endl; return 0;}
    }
    cout<<-1<<endl;
}