#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int k=0;
    for (int i=n; i>=1; i--)
    if (a[i]!=a[n]) {k=i; break;}
    if (k>=m) cout<<-1<<endl; else cout<<k<<endl;
}