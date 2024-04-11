#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, T;
    cin>>N>>T;
    int x;
    for(int i=1; i<=N; i++)
    {
        cin>>x;
        T -= (86400-x);
        if(T<=0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}