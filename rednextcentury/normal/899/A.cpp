#include <bits/stdc++.h>

using namespace std;
int a[10];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int x = min(a[2],a[1]);
    a[2]-=x;
    a[1]-=x;
    cout<<x+a[1]/3<<endl;
}