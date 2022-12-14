#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,m;
    cin>>a>>m;
    for (int i=0;i<2*m;i++)
    {
        a=a+a%m;
        a%=m;
        if (a==0){
        cout<<"Yes"<<endl;
        return 0;}
    }
    cout<<"No"<<endl;
}