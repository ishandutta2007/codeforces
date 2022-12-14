#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ret=min(a[n-1]-1,1000000-a[0]);
    for (int i=0;i+1<n;i++)
    {
        ret=min(ret,max(a[i]-1,1000000-a[i+1]));
    }
    cout<<ret<<endl;
}