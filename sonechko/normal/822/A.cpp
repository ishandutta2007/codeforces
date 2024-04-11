#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair

int main()
{
    int n,m;
    cin>>n>>m;
    if (n<m)
    {
        int l=1;
        for (int i=1; i<=n; i++)
            l*=i;
        cout<<l<<endl;
    } else
    {
        int l=1;
        for (int i=1; i<=m; i++)
            l*=i;
        cout<<l<<endl;
    }
}