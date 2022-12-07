#include <iostream>
#include <fstream>
#define MAXN 1100
using namespace std;
int N, K;
bool DP[MAXN][2*MAXN][3];
char x[MAXN];
char s[MAXN];
bool makable(int n, int k)
{
    if(DP[n][k][0]||DP[n][k][1]||DP[n][k][2])
    {
        return true;
    }
    return false;
}
int main()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        cin>>x[i];
    }
    DP[0][MAXN][0] = DP[0][MAXN][1] = DP[0][MAXN][2] = true;
    K--;
    for(int i=1; i<=N; i++)
    {
        if(i==N)
        {
            K++;
        }
        for(int j=MAXN-K; j<=MAXN+K; j++)
        {
            if(x[i]=='?')
            {
                for(int k=0; k<3; k++)
                {
                    if(makable(i-1, j-k+1))
                    {
                        DP[i][j][k] = true;
                    }
                }
            }
            if(x[i]=='L')
            {
                if(makable(i-1, j+1))
                {
                    DP[i][j][0] = true;
                }
            }
            if(x[i]=='D')
            {
                if(makable(i-1, j))
                {
                    DP[i][j][1] = true;
                }
            }
            if(x[i]=='W')
            {
                if(makable(i-1, j-1))
                {
                    DP[i][j][2] = true;
                }
            }
        }
    }
    if(makable(N, K+MAXN))
    {
        for(int i=N; i>=1; i--)
        {
            if(DP[i][K+MAXN][0])
            {
                s[i] = 'L';
                K++;
            }
            else if(DP[i][K+MAXN][1])
            {
                s[i] = 'D';
            }
            else
            {
                s[i] = 'W';
                K--;
            }
        }
    }
    else if(makable(N, MAXN-K))
    {
        for(int i=N; i>=1; i--)
        {
            if(DP[i][MAXN-K][0])
            {
                s[i] = 'L';
                K--;
            }
            else if(DP[i][MAXN-K][1])
            {
                s[i] = 'D';
            }
            else
            {
                s[i] = 'W';
                K++;
            }
        }
    }
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1; i<=N; i++)
    {
        cout<<s[i];
    }
    cout<<""<<endl;
}