#include <iostream>
#include <fstream>
#define MAXN 29
using namespace std;
typedef long long ll;
ll g[MAXN][MAXN];
ll maxp[MAXN][MAXN], minp[MAXN][MAXN];
int N, Q; ll K;
int curx, cury;
int main()
{
    cin>>N;
    for(int i=N-1; i>=1; i--)
    {
        for(int j=N; j>=0; j--)
        {
            if(j > 0) g[i][j] = 1+maxp[i+1][j-1]-min(minp[i+1][j], minp[i][j+1]);
            maxp[i][j] = max(maxp[i][j+1], maxp[i+1][j]) + g[i][j];
            minp[i][j] = min(minp[i][j+1], minp[i+1][j]) + g[i][j];
        }
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>K;
        curx = cury = 1;
        cout<<1<<" "<<1<<endl;
        K -= g[1][1];
        while(curx != N || cury != N)
        {
            if(cury != N && K >= minp[curx][cury+1])
            {
                cout<<curx<<" "<<cury+1<<endl;
                K -= g[curx][cury+1];
                ++cury;
            }
            else
            {
                cout<<curx+1<<" "<<cury<<endl;
                K -= g[curx+1][cury];
                ++curx;
            }
        }
    }
}