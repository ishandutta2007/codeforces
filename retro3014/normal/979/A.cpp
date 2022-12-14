#include <iostream>

using namespace std;
long long N;

int main()
{
    cin>>N;
    if(N==0)
    {
        cout<<"0";
        return 0;
    }
    if((N+1)%2==0)
    {
        cout<<(N+1)/2;
    }
    else
    {
        cout<<N+1;
    }
    return 0;
}