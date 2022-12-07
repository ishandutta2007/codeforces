#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int T;
ll N;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        if(N % 2050 != 0)
        {
            cout<<-1<<endl;
        }
        else
        {
            N = N/2050;
            int ans = 0;
            while(N)
            {
                ans += (N % 10);
                N /= 10;
            }
            cout<<ans<<endl;
        }
    }
}