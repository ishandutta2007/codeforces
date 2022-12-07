#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    long long a, b;
    cin>>a>>b;
    int counter = 0;
    while(a<=b)
    {
        a = a*3;
        b = b*2;
        counter++;
    }
    cout<<counter<<endl;
}