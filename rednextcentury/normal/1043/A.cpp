#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int cur=0;
    int opp=0;
    int k=a[n-1];
    for (int i=0;i<n;i++)
    {
        opp+=a[i];
        cur+=a[n-1]-a[i];
    }
    while(cur<=opp)
    {
        cur+=n;
        k++;
    }
    cout<<k<<endl;
}