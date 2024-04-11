# include <iostream>
# include <stdio.h>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
using namespace std;
int a[10000];
int main()
{
    int n,s;
    int sum=0;
    int m=0;
    cin>>n>>s;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if (a[i]>m)
            m=a[i];
    }
    if (sum-m<=s)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}