#include <iostream>
#include <fstream>
using namespace std;
int N, M;
int a, b;
int x;
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>a>>b;
        if(x >=a)
        {
            x = max(x, b);
        }
    }
    if(x>=M)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}