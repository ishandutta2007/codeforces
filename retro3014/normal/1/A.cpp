#include <iostream>

using namespace std;

typedef long long ll;

ll N, M, K;

int main()
{
    cin>>N>>M>>K;
    N=(N-1)/K+1;
    M=(M-1)/K+1;
    cout<<N*M;
    return 0;
}