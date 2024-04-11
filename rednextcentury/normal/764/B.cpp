#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[1000000];
int main()
{
    fast
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n/2;i++)
        if (i%2)
            swap(a[i],a[n-i+1]);
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}