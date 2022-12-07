#include <iostream>
#include <fstream>
using namespace std;
int power(int x)
{
    if(x==0)
    {
        return 1;
    }
    else
    {
        return 2*power(x-1);
    }
}
int main()
{
    int M, N;
    cin>>N>>M;
    if(N > 29)
    {
        cout<<M<<endl;
        return 0;
    }
    cout<< M%(power(N))<<endl;
}