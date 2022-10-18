#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 11;

int a[N],use[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<=m; i++)
    {
              int l;
              cin>>l;
              use[l]=1;
    }
    for (int i=1; i<=n; i++)
    if (use[a[i]]) cout<<a[i]<<" ";
}