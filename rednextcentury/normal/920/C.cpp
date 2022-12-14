#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    string s;
    cin>>s;
    int i=0;
    while(i<n-1)
    {
        while(s[i]=='0' && i<n)
            i++;
        if (i==n)break;
        int l=i;
        int r=i;
        while(s[r]=='1' && i<n)r++;
        sort(a+l,a+r+1);
        i=r;
    }
    bool sorted=true;
    for (int i=1;i<n;i++)
        if (a[i]<a[i-1])
            sorted=false;
    if (sorted)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}