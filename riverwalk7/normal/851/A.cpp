#include <iostream>
#include <fstream>
using namespace std;
int N, K, T;
int main()
{
    cin>>N>>K>>T;
    cout<<min(K, min(T, N+K-T));
}