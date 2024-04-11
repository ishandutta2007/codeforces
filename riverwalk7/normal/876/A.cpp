#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, a, b, c;
    cin>>N>>a>>b>>c;
    if(N==1)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        cout<<min(a, b) + (N-2)*min(min(a, b), c)<<endl;
    }
}