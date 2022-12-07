#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if((i+j)%2 == 0)
            {
                cout<<"W";
            }
            else
            {
                cout<<"B";
            }
        }
        cout<<""<<endl;
    }
}