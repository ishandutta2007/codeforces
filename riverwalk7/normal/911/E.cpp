#include <iostream>
#include <fstream>
#define MAXN 200100
using namespace std;
int p[MAXN];
int N, K;
bool test(int x, int y, int z)
{
    if(x>y)
    {
        return true;
    }
    else if(p[x] > z+y-x)
    {
        return false;
    }
    else if(p[x]!=0)
    {
        return test(x+1, x+p[x]-z, z)&&test(x+p[x]-z+1, y, p[x]+1);
    }
    else
    {
        p[x] = z+y-x;
        test(x+1, x+p[x]-z, z);
        test(x+p[x]-z+1, y, p[x]+1);
        return true;
    }
}
int main()
{
    cin>>N>>K;
    for(int i=0; i<K; i++)
    {
        cin>>p[i];
    }
    if(test(0, N-1, 1))
    {
        for(int i=0; i<N-1; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<p[N-1]<<endl;
        return 0;
    }
    else
    {
        cout<<-1<<endl;
        return 0;
    }
}