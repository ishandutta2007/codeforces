#include<iostream>

using namespace std;

int main ()
{
    int x1,y1,x2,y2,p;

    cin>>x1>>y1>>x2>>y2;

    if(x1>x2)x1=x1-x2;
    else x1=x2-x1;
    if(y1>y2)y1=y1-y2;
    else y1=y2-y1;

    cin>>x2>>y2;

    if(x1%x2==0 && y1%y2==0)
    {
        p=x1/x2-y1/y2;
        if(p<0)p=-p;
        if(p%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}