#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if ((i+j)%2)cout<<"W";
            else cout<<"B";
        }
        cout<<endl;
    }
}