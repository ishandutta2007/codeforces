#include <iostream>
#include <fstream>
using namespace std;
int N, ans;
int main()
{
    cin>>N;
    for(int i=1; i<N; i++)
    {
        if(N%i==0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}