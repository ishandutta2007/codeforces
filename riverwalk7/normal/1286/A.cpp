#include <iostream>
#include <fstream>
#define MAXN 110
using namespace std;
int DP[MAXN][MAXN][2]; // # of evens so far
int a[MAXN];
int N;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            for(int k=0; k<2; k++)
            {
                DP[i][j][k] = MAXN;
            }
        }
    }
    if(a[0] == 0)
    {
        DP[0][0][1] = DP[0][1][0] = 0;
    }
    else if(a[0] % 2 == 1)
    {
        DP[0][0][1] = 0;
    }
    else
    {
        DP[0][1][0] = 0;
    }
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<=N/2; j++)
        {
            if(a[i] == 0)
            {
                if(j) DP[i][j][0] = min(DP[i-1][j-1][0], DP[i-1][j-1][1]+1);
                DP[i][j][1] = min(DP[i-1][j][0]+1, DP[i-1][j][1]);
            }
            else if(a[i] % 2 == 0)
            {
                if(j) DP[i][j][0] = min(DP[i-1][j-1][0], DP[i-1][j-1][1]+1);
            }
            else
            {
                DP[i][j][1] = min(DP[i-1][j][0]+1, DP[i-1][j][1]);
            }
        }
    }
    cout<<min(DP[N-1][N/2][0], DP[N-1][N/2][1])<<endl;
}