#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, x, ans; ans = 0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        ans = max(ans, min(x-1, 1000000-x));
    }
    cout<<ans<<endl;
}