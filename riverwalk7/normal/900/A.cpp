#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int N;
int x[MAXN], y[MAXN];
int a, b;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]>0)
        {
            a++;
        }
        else
        {
            b++;
        }
        if(a>1&&b>1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}