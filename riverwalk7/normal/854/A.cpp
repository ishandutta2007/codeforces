#include <iostream>
using namespace std;
int N;
int gcd(int a, int b)
{
    if(b%a==0)
    {
        return a;
    }
    else
    {
        return gcd(b%a,a);
    }
}
int main()
{
    cin>>N;
    for(int i=N/2+1; i<N; i++)
    {
        if(gcd(i, N) == 1)
        {
            cout<<N-i<<" "<<i<<endl;
            return 0;
        }
    }
}