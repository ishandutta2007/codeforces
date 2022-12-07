#include <iostream>
#include <fstream>
#define MAXN 510
using namespace std;
bool b[2];
int T, N;
int x[MAXN];
int c;
bool s()
{
    for(int i=0; i<N-1; i++)
    {
        if(x[i] > x[i+1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        b[0] = b[1] = false;
        for(int j=0; j<N; j++)
        {
            cin>>x[j];
        }
        for(int j=0; j<N; j++)
        {
            cin>>c; b[c] = true;
        }
        if(b[0] && b[1])
        {
            cout<<"Yes"<<endl;
        }
        else if(s())
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}