#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int mn=1000000;
    for (int i=1;i<=n;i++)
        mn=min(mn,a[i]);
    cout<<mn<<endl;
}