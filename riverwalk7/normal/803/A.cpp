#include <iostream>
#define MAXN 105
using namespace std;
int N, K;
int grid[MAXN][MAXN];
int main()
{
    cin>>N>>K;
    if(K>N*N)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            if(j==i&&K>=1)
            {
                grid[i][j] = 1;
                K--;
            }
            else if(K>=2)
            {
                grid[i][j] = grid[j][i] = 1;
                K-=2;
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<""<<endl;
    }
}