#include <iostream>
#include <fstream>
using namespace std;
int N;
int x[10];
int ans;
int main()
{
    for(int i=1; i<10; i++)
    {
        x[i] = ((1<<i)-1)*(1<<(i-1));
    }
    cin>>N;
    for(int i=1; i<10; i++)
    {
        if(N%x[i]==0)
        {
            ans = x[i];
        }
    }
    cout<<ans<<endl;
}