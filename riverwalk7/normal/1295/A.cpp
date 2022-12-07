#include <iostream>
#include <fstream>
using namespace std;
int T, N;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        if(N % 2== 1)
        {
            cout<<7; N -= 3;
        }
        while(N > 0)
        {
            N -= 2; cout<<1;
        }
        cout<<""<<endl;
    }
}