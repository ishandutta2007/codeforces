#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ll K, N;
int main()
{
    cin>>N>>K;
    if(K==1)
    {
        cout<<N<<endl;
        return 0;
    }
    if(K>=2)
    {
        for(ll i=1;; i*=2)
        {
            if(i > N)
            {
                cout<<i-1<<endl;
                return 0;
            }
        }
    }
}