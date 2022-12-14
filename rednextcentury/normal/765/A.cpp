#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    for (int i=0;i<=n;i++)cin>>s;
    if (n%2==0)
        cout<<"home"<<endl;
    else
        cout<<"contest"<<endl;
}