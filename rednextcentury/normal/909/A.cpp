#include<bits/stdc++.h>
using namespace std;


int main()
{
    string a,b;
    cin>>a>>b;
    string c="";
    c+=a[0];
    for (int i=1;i<a.size();i++)
    {
        if (a[i]<b[0])
            c+=a[i];
        else break;
    }
    c+=b[0];
    cout<<c<<endl;
}