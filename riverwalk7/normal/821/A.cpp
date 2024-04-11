#include <iostream>
#include <fstream>
#define MAXN 51
using namespace std;
int N;
bool flag;
int grid[MAXN][MAXN];
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j]!=1)
            {
                flag = false;
                for(int k=0; k<N; k++)
                {
                    for(int l=0; l<N; l++)
                    {
                        if(grid[i][k]+grid[l][j]==grid[i][j])
                        {
                            flag = true;
                        }
                    }
                }
                if(!flag)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
}