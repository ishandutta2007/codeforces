#include <iostream>
using namespace std;
int main()
{
    int N; cin>>N;
    if(N==0)
    {
        cout<<1<<endl;
    }
    else if(N%4==0)
    {
        cout<<6<<endl;
    }
    else if(N%4==1)
    {
        cout<<8<<endl;
    }
    else if(N%4==2)
    {
        cout<<4<<endl;
    }
    else
    {
        cout<<2<<endl;
    }
}