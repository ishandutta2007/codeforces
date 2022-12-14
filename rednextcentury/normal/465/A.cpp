#include <iostream>
# include <vector>
# include<algorithm>
# include <string>
using namespace std;
int a[1000];
int b[1000];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int i=0;i<n;i++)
        a[i]=(int)s[i]-48;
    int rem=1;
    for (int i=0;i<n;i++)
    {
        b[i]=a[i];
        b[i]+=rem;
        if (b[i]<2)
            rem=0;
        else
            b[i]=b[i]%2;
        if (b[i]!=a[i])
            ans++;
    }
    cout<<ans<<endl;
}