#include <iostream>
#define MAXN 1010
using namespace std;
int R, C;
int grid[MAXN][MAXN];
int rsum[MAXN];
int csum[MAXN];
int sum;
char p;
int main()
{
    cin>>R>>C;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>p;
            if(p=='*')
            {
                grid[i][j] = 1;
                sum++;
            }
        }
    }
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            rsum[i] += grid[i][j];
            csum[j] += grid[i][j];
        }
    }
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(rsum[i]+csum[j]-grid[i][j] == sum)
            {
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}