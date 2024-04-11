# include <iostream>
# include <stdio.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    if (b.length()!=n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]!=b[n-i-1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}