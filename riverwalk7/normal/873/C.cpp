#include <iostream>
#include <fstream>
#define MAXN 110
using namespace std;
int N, M, K;
int a[MAXN][MAXN];
int x, y;
int curx, cury;
int p, q;
int main()
{
    cin>>N>>M>>K;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<M; i++)
    {
        q = 0;
        curx = cury = 0;
        for(int j=0; j<N; j++)
        {
            if(a[j][i]==1)
            {
                p = 0;
                for(int k=j; k<min(N, j+K); k++)
                {
                    p += a[k][i];
                }
                if(p > curx)
                {
                    curx = p;
                    cury = q;
                }
                ++q;
            }
        }
        x += curx;
        y += cury;
    }
    cout<<x<<" "<<y<<endl;
}