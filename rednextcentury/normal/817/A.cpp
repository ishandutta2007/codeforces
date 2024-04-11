#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y;
    cin>>x>>y;
    if (abs(a-c)%x==0 && abs(b-d)%y==0 && (abs(a-c)/x)%2 == (abs(b-d)/y)%2)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}