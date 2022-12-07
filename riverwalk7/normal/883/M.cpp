#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1!=x2 && y1!=y2)
    {
        cout<<2*(abs(x2-x1)+abs(y2-y1)+2)<<endl;
    }
    else
    {
        cout<<2*(abs(x2-x1)+abs(y2-y1)+3)<<endl;
    }
}