#include <iostream>
#include <fstream>
#define MAXN 510
using namespace std;
typedef long long ll;
int N;
ll x[MAXN];
ll ans;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i];
    }
    for(int i=0; i<N; i++)
    {
        ans = max(ans, x[i]);
        for(int j=i+1; j<N; j++)
        {
            ans = max(ans, x[i] | x[j]);
            for(int k=j+1; k<N; k++)
            {
                ans = max(ans, x[i] | x[j] | x[k]);
            }
        }
    }
    cout<<ans<<endl;
}