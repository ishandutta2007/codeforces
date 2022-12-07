#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N;
bool isPrime(int x)
{
    for(int i=2; i<x; i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>N;
    for(int i=1;; i++)
    {
        if(!isPrime(N*i+1))
        {
            cout<<i<<endl;
            return 0;
        }
    }
}