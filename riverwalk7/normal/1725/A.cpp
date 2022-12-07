#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll N, M;
    cin>>N>>M;
    if(M != 1)
    {
        cout<<N*(M-1)<<endl;
    }
    else
    {
        cout<<N-1<<endl;
    }
}