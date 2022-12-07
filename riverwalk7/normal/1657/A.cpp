#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int T;
int x, y;
int d;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>x>>y;
        d = sqrt(x*x+y*y);
        if(x == 0 && y == 0)
        {
            cout<<0<<endl;
        }
        else if(d*d == x*x+y*y)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
    }
}