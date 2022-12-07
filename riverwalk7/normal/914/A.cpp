#include <iostream>
using namespace std;
bool flag;
int main()
{
    int ans = -1234567;
    int N; cin>>N;
    int a;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        flag = true;
        for(int j=0; j<=1000; j++)
        {
            if(a==(j*j))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
           ans = max(ans, a);
        }
    }
    cout<<ans<<endl;
}