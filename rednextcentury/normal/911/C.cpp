#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int x=a[0],y=a[1],z=a[2];
    if (x==1)
        cout<<"YES"<<endl;
    else if (x==2 && y==2)
        cout<<"YES"<<endl;
    else if (x==2 && y==4 && z==4)
        cout<<"YES"<<endl;
    else if (x==2 && y>2)
        cout<<"NO"<<endl;
    else if (x==3 && y==3 && z==3)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}