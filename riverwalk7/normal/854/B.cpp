#include <iostream>
using namespace std;
int main()
{
    int N, K;
    cin>>N>>K;
    if(K==N||K==0)
    {
        cout<<0<<" ";
    }
    else
    {
        cout<<1<<" ";
    }
    cout<<min(2*K, N-K)<<endl;
}