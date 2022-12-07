#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int A, B, C, T;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>A>>B;
        C = abs(A-B);
        for(int i=0; i<=100000; i++)
        {
            C -= i;
            if(C <= 0 && C%2 == 0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}