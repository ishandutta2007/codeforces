#include <iostream>
#include <fstream>
using namespace std;
int N, x;
int a;
int counter;
int main()
{
    cin>>N>>x;
    counter = x;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        if(a < x)
        {
            counter--;
        }
        if(a==x)
        {
            counter++;
        }
    }
    cout<<counter<<endl;
}