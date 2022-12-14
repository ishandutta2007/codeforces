#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <queue>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
char bus[100][100];
int main()
{
    bus[5][25]='+';
    bus[0][0]='+';
    bus[5][0]='+';
    bus[0][25]='+';
    for (int i=1;i<25;i++)
    {
        bus[0][i]='-';
        bus[5][i]='-';
    }
    for (int i=1;i<5;i++)
    {
        bus[i][0]='|';
        bus[i][25]='|';
    }
    for (int i=1;i<5;i++)
    {
        for (int x=1;x<25;x++)
        {
            if (i==3 || (x%2)==0)
            bus[i][x]='.';
            else
            bus[i][x]='#';
        }
    }
    bus[1][23]=bus[2][23]=bus[4][23]='|';
    bus[1][24]='D';
    bus[3][1]='#';
    int k;
    cin>>k;
    int x=0,y=0;
    while(k>0)
    {
        if (bus[x][y]=='#')
            bus[x][y]='O',k--;
        x++;
        if (x==5)
            x=0,y++;
    }
    for (int i=0;i<=5;i++)
    {
        for (int x=0;x<=25;x++)
        {
            cout<<bus[i][x];
        }
        if (i==1 || i==4)
            cout<<")";
        cout<<endl;
    }
}