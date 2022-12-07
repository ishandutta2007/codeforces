#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, K, a;
    int ans = 999999999;
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        if(K%a==0)
        {
            ans = min(ans, K/a);
        }
    }
    cout<<ans<<endl;
}