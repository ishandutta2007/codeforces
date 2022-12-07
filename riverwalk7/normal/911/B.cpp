#include <iostream>
#include <fstream>
using namespace std;
int N, A, B;
int ans;
int main()
{
    cin>>N>>A>>B;
    for(int i=1; i<N; i++)
    {
        ans = max(ans, min(A/i, B/(N-i)));
    }
    cout<<ans<<endl;
}