# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
bool played[1000][1000];
int games[2][1000000];
int main()
{
    int n,k;
    int g=0;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        int h=k;
        for (int x=0;x<n;x++)
        {
            if (played[i][x]==1 || played[x][i]==1 || i==x)
                continue;
            games[0][g]=i+1;
            games[1][g]=x+1;
            g++;
            played[x][i]=1;
            h--;
            if (h==0)
                break;
        }
        if (h>0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<g<<endl;
    for (int i=0;i<g;i++)
        printf("%d %d\n",games[0][i],games[1][i]);
}