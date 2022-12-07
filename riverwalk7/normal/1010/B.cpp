#include <iostream>
#include <fstream>
#define MAXN 32
using namespace std;
int M, N; int c;
int b[MAXN];
int lbound, hbound, avg;
int x;
int main()
{
    cin>>M>>N;
    for(int i=0; i<N; i++)
    {
        cout<<1<<endl;
        cin>>c;
        if(c==0)
        {
            return 0;
        }
        if(c==1)
        {
            b[i] = 1;
        }
        if(c==-1)
        {
            b[i] = -1;
        }
    }
    lbound = 1; hbound = M;
    while(true)
    {
        avg = (lbound + hbound)/2;
        cout<<avg<<endl;
        cin>>c;
        if(c==0)
        {
            return 0;
        }
        if((c*b[x]) == 1)
        {
            lbound = avg+1;
        }
        if((c*b[x]) == -1)
        {
            hbound = avg-1;
        }
        ++x;
        x %= N;
    }
}