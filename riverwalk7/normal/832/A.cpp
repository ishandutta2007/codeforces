#include <iostream>
using namespace std;
int main()
{
    long long n, k;
    cin>>n>>k;
    long long s = n/k;
    if(s%2==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}