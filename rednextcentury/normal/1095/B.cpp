#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<min(a[n-2]-a[0],a[n-1]-a[1])<<endl;
}