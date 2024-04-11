#include <iostream>
#include <fstream>
#define LIM 1000000
using namespace std;
int a, b, c;
int main()
{
    cin>>a>>b>>c;
    for(int i=1; i<=LIM; i++)
    {
        a *= 10;
        if((a/b)==c)
        {
            cout<<i<<endl;
            return 0;
        }
        a %= b;
    }
    cout<<-1<<endl;
}