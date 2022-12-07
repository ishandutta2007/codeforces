#include <iostream>
#include <fstream>
#define MAXN 30
using namespace std;
int x[MAXN];
int Q;
int N, c;
int lg(int x)
{
    if(x == 1) return 0;
    else return 1+lg(x/2);
}
int main()
{
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        for(int j=0; j<MAXN; j++)
        {
            x[j] = false;
        }
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>c; ++x[lg(c)];
        }
        for(int j=0; j<11; j++)
        {
            x[j+1] += x[j]/2;
        }
        if(x[11]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}