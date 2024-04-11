#include <iostream>
#include <fstream>
#define MAXN 110
using namespace std;
int N, K;
int a[MAXN];
int x;
int ans;
int main()
{
    cin>>N>>K>>x;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        if(i >= (N-K))
        {
            ans += x;
        }
        else
        {
            ans += a[i];
        }
    }
    cout<<ans<<endl;
}