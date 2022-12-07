#include <iostream>
#include <fstream>
#define MAXN 20
using namespace std;
int N; int a[MAXN];
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<(1<<N); i++)
    {
        int cur = 0;
        for(int j=0; j<N; j++)
        {
            if((1<<j) & i)
            {
                cur += a[j];
            }
            else
            {
                cur -= a[j];
            }
        }
        if(cur%360==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}