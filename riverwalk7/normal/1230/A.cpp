#include <iostream>
#include <fstream>
using namespace std;
int a[4];
int cur, tot;
int main()
{
    for(int i=0; i<4; i++)
    {
        cin>>a[i]; tot += a[i];
    }
    for(int i=1; i<15; i++)
    {
        cur = 0;
        for(int j=0; j<4; j++)
        {
            if((1<<j) & i)
            {
                cur += a[j];
            }
        }
        if(tot == cur*2)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}