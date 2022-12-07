#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int A, B, C;
    cin>>A>>B>>C;
    for(int i=1; i<=A; i++)
    {
        for(int j=1; j<=B; j++)
        {
            C-=2;
            if(C==-1)
            {
                cout<<i<<" "<<j<<" "<<'L'<<endl;
                break;
            }
            else if(C==0)
            {
                cout<<i<<" "<<j<<" "<<'R'<<endl;
                break;
            }
        }
    }
}