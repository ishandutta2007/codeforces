#include <iostream>
#include <fstream>
using namespace std;
int A, B, C;
int factorial(int x)
{
    if(x==0)
    {
        return 1;
    }
    else
    {
        return x*factorial(x-1);
    }
}
int main()
{
    cin>>A>>B;
    C = min(A, B);
    cout<<factorial(C)<<endl;
}