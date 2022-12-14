#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin>>a>>b;
    if(a==b)
    {
        cout<<"=";
        return 0;
    }
    if(a==1)
    {
        cout<<"<";return 0;
    }
    if(b==1)
    {
        cout<<">";return 0;
    }
    if (a==2 && b==3)
    {
        cout<<"<";return 0;
    }
    if(a==3 && b==2)
    {
        cout<<">";return 0;
    }
    if(a==4 && b==2)
    {
        cout<<"=";return 0;
    }
    if(a==2 && b==4)
    {
        cout<<"=";return 0;
    }
    if(a<b)
    {
        cout<<">";return 0;
    }
    cout<<"<";
    return 0;
}