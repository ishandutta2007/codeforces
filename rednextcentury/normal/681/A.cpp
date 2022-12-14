#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int a,b;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s>>a>>b;
        if (a>=2400 && b>a)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}