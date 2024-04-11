#include <iostream>
#include <fstream>
#define MAXN 510
using namespace std;
int N, M;
int m[MAXN][MAXN];
int sum;
int main()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin>>m[i][j];
        }
    }
    for(int i=N; i>=1; i--)
    {
        for(int j=M; j>=1; j--)
        {
            if(m[i][j] == 0)
            {
                m[i][j] = min(m[i+1][j], m[i][j+1])-1;
            }
        }
    }
    for(int i=N; i>=1; i--)
    {
        for(int j=M; j>=1; j--)
        {
            if(m[i][j] <= m[i-1][j] || m[i][j] <= m[i][j-1])
            {
                cout<<-1<<endl;
                return 0;
            }
            else
            {
                sum += m[i][j];
            }
        }
    }
    cout<<sum<<endl;
}