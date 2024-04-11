#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast
    int a,b;
    cin>>a>>b;
    if (abs(a-b)<=1 && a+b>0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}