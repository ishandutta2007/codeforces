#include <iostream>
#include <fstream>
using namespace std;
int a;
int s = 3;
int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        if(a==s)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for(int j=1; j<=3; j++)
        {
            if(j!=s&&j!=a)
            {
                s = j;
                break;
            }
        }
    }
    cout<<"YES"<<endl;
}