#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N, K, c, a;
int main()
{
    cin>>N>>K;
    int c = 0;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        c = __gcd(c, a);
    }
    c = __gcd(c, K);
    cout<<K/c<<endl;
    for(int i=0; i<K; i+=c)
    {
        cout<<i<<" ";
    }
}