#include <iostream>
using namespace std;
int c;
int main()
{
    int N;
    cin>>N;
    int b = N;
    while(N >= 10)
    {
        N/=10;
        c++;
    }
    N++;
    while(c>0)
    {
        c--;
        N *= 10;
    }
    cout<<N-b<<endl;
}