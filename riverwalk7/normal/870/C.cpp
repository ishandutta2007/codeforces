#include <iostream>
using namespace std;
int main()
{
    int q, x;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        cin>>x;
        if(x%4==0)
        {
            if(x == 0)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<x/4<<endl;
            }
        }
        if(x%4==1)
        {
            if(x<=5)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<(x-5)/4<<endl;
            }
        }
        if(x%4==2)
        {
            if(x<=2)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<(x-2)/4<<endl;
            }
        }
        if(x%4==3)
        {
            if(x<=11)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<(x-7)/4<<endl;
            }
        }
    }
}