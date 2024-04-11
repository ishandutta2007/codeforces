#include <iostream>
#include <fstream>
#define MAXN 52
using namespace std;
int T;
int c, c1, c2;
int M, N;
bool x[MAXN], y[MAXN];
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>M;
        c1 = c2 = 0;
        for(int j=0; j<N; j++)
        {
            x[j] = 1;
        }
        for(int j=0; j<M; j++)
        {
            y[j] = 1;
        }
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                cin>>c;
                if(c == 1)
                {
                    x[j] = false; y[k] = false;
                }
            }
        }
        for(int j=0; j<N; j++)
        {
            if(x[j]) ++c1;
        }
        for(int j=0; j<M; j++)
        {
            if(y[j]) ++c2;
        }
        if(min(c1, c2) % 2 == 0)
        {
            cout<<"Vivek"<<endl;
        }
        else
        {
            cout<<"Ashish"<<endl;
        }
    }
}