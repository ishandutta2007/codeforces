#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
char a[1000][1000];
int main ()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int X=-1,Y=-1;
    int num=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='B')
            {
                num++;
                if (X==-1)
                    X=i,Y=j;
            }
        }
    }
    int x=1;
    while(x*x!=num)x++;
    cout<<X+x/2+1<<' '<<Y+x/2+1<<endl;
}