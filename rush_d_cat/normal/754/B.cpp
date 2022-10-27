#include <iostream>
#include <cstdio>
using namespace std;
char mp[6][6];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
int main()
{
    for(int i=1;i<=4;i++) scanf("%s", mp[i]+1);
    int ok = 0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(mp[i][j] == '.')
            {
                mp[i][j] = 'x';
                for(int i_=1;i_<=4;i_++)
                {
                    for(int j_=1;j_<=4;j_++)
                    {
                        for(int k=0;k<8;k++)
                        {
                            if(mp[i_][j_] == 'x' && mp[i_+dx[k]][j_+dy[k]] == 'x' && mp[i_-dx[k]][j_-dy[k]] == 'x')
                            {
                                ok = 1;
                            }
                        }
                    }
                }
                mp[i][j] = '.';
            }
        }
    }
    cout << (ok?"YES":"NO") << endl;
}