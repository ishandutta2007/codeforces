# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
string s[1000];
int a[1000];
int b[1000];
int main()
{
    int n,tot;
    cin>>n>>tot;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int m=0;
    for (int i=0;i<tot;i++)
    {
        string k;
        cin>>k;
        bool p=0;
        for (int j=0;j<m;j++)
            if (s[j]==k) p=1,b[j]++;
        if (!p)
            s[m]=k,b[m++]=1;
    }
    sort(b,b+m);
    int mn=0,mx=0;
    int l=0,r=n-1;
    for (int i=m-1;i>=0;i--)
    {
        mn+=b[i]*a[l];
        mx+=b[i]*a[r];
        l++,r--;
    }
    cout<<mn<<" "<<mx<<endl;
}